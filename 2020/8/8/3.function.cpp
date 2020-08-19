/*************************************************************************
    > File Name: 3.function.cpp
    > Author:赵睿 
    > Mail: 1767153298@qq.com
    > Created Time: 2020年08月08日 星期六 15时26分31秒
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

namespace haizei {
    template<typename RT, typename ...PARAMS> class base;
    template<typename RT, typename ...PARAMS> class base {
    public:
        virtual RT operator()(PARAMS...) = 0;
        virtual base<RT, PARAMS...> *getCopy() = 0;
        virtual ~base() {};
    };

    template<typename RT, typename ...PARAMS> 
    class normal_func : public base<RT, PARAMS...> {
    public:
        typedef RT (*func_type)(PARAMS...);
        normal_func(func_type func) : ptr(func) {};

        virtual base<RT, PARAMS...> *getCopy() override {
            return new normal_func<RT, PARAMS...>(ptr);
        }

        virtual RT operator()(PARAMS... args) override {
            return this->ptr(args...);
        };
    private:
        func_type ptr;
    };

    template<typename C, typename RT, typename ...PARAMS> 
    class functor : public base<RT, PARAMS...> {
    public:
        functor(C &func) : ptr(func) {};
        virtual base<RT, PARAMS...> *getCopy() override {
            return new functor<C, RT, PARAMS...>(ptr);
        }
        virtual RT operator()(PARAMS... args) override {
            return this->ptr(args...);
        };
    private:
        C &ptr;
    };

    template<typename RT, typename ...PARAMS> class function;
    template<typename RT, typename ...PARAMS>
    class function<RT(PARAMS...)>{
    public:
        typedef normal_func<RT, PARAMS...> T1;

        function(RT (*func)(PARAMS...))
        : ptr(new normal_func<RT, PARAMS...>(func)) {
            cout << "normal function constructor" << endl;
        }

        function(function<RT(PARAMS...)> &&func) {
            this->ptr = func.ptr;
            func.ptr = nullptr;
        }

        function(const function &f) {
            this->ptr = f.ptr->getCopy();
        }
    

        template<typename T>
        function(T a) 
        : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(a)) {
            cout << "function object constructor" << endl;
        }

        RT operator()(PARAMS... args) {
            return this->ptr->operator()(args...);
        }

        ~function() {
            if (ptr != nullptr) delete ptr;
        }
        typedef RT (*func)(PARAMS...);
        func get_function() {
            return (func) this->ptr;
        }
    private:
        base<RT, PARAMS...> *ptr;
    };
};

void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
    return ;
}

int add(int a, int b) {
    return a + b;
}

struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b;
    }
};

#if 0
class FunctionCnt {
public : 
    FunctionCnt(function<int(int, int)> g)  : g(g) , __cnt(0) {} 
    int operator()(int a, int b) {
        __cnt++;
        return g(a, b);
    }
    int cnt() { return __cnt; }
private:
    int __cnt;
    function<int(int, int)> g;
};
#endif

template<typename T, typename ...ARGS> class FunctionCnt;
template<typename T, typename ...ARGS>
class FunctionCnt<T(ARGS...)> {
public:
    FunctionCnt() : cnt(0) {}
    FunctionCnt(function<T(ARGS...)> g) : cnt(0), func(g) {}
    FunctionCnt(FunctionCnt<const T(ARGS...)> &g) : cnt(0), func(g.func) {}


    T operator()(ARGS... args) {
        this->cnt++;
        return func(args...);
    }

    void operator=(function<T(ARGS...)> g) {
        this->cnt = 0;
        this->func = g;
    }

    void operator=(FunctionCnt<T(ARGS...)> g) {
        this->cnt = 0;
        this->func = g.func;
    }

    int get_cnt() {
        return this->cnt;
    }
private:
    function<T(ARGS...)> func;
    int cnt;
};



int main() {
    MaxClass mmax;
    f(add);
    f(mmax);
    haizei::function<int(int, int)> f1 = add;
    haizei::function<int(int, int)> f2 = mmax;
    cout << f1(1, 3) << endl;
    //FunctionCnt<int(int, int)> f3 = f1;
    //cout << f1(1, 3) << endl;
    //cout << f3(1, 3) << endl;
    return 0;
}
