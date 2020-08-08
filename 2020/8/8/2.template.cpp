/*************************************************************************
	> File Name: 2.template.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月06日 星期四 11时47分17秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class A {
public:
    A(int x) : x(x) {}
    int x;
};

class B {
public:
    B(int y) : y(y) {}
    int y;
};

int operator+(const A &a, const B &b) {
    return a.x + b.y;
}

namespace haizei {
    template<typename T, typename U>
    auto add(T a, U b) -> decltype(a + b) {
        return a + b;
    }

    template<typename T, typename U>
    auto max(T a, U b) -> decltype(a > b ? a : b) {
        return (a < b ? b : a);
    }

    template<typename T, typename U>
    auto min(T a, U b) -> decltype(a < b ? a : b) {
        return (a < b ? a : b);
    }

    template<>
    int add(int a, int b) {
        return a + b;
    }

    template<typename T, typename U>
    auto add(T *a, U *b) ->decltype(add(*a, *b)) {
        return add(*a, *b);
    }

    class PrintAny {
    public:
        template <typename T>
        void operator()(const T &A) {
            cout << A << endl;
        }
    };

    template<typename T>
    class FoolPrintAny {
    public:
        void operator()(const T &a) {
            cout << a << endl;
        }
    };

    template<>
    class FoolPrintAny<int> {
    public:
        void operator()(const int &a) {
            cout << "naughty : ";
            cout << 2 * a << endl;
        }
    };

    template<typename T>
    void printAny(const T &a) {
        cout << a << endl;
    }

    template<typename T, typename... ARGS>
    void printAny(const T &a, ARGS... args) {
        cout << a << " ";
        printAny(args...);
    };

    template<int val, typename T, typename ...ARGS> class ARG;
    template<int val, typename T, typename ...ARGS>
    class ARG {
    public:
        typedef typename ARG<val - 1, ARGS...>::__type __type;
    };

    template<typename T, typename ...ARGS>
    class ARG<0, T, ARGS...> {
    public:
        typedef T __type;
    };

    template<typename T>
    class ARG<0, T> {
    public:
        typedef T __type;
    };


    template<typename T>
    T sum(T a) {
        return a;
    }

    template<typename T, typename ...ARGS>
    T sum(T a, ARGS... args) {
        return a + sum(args...);
    }

    template<typename T, typename ...ARGS> class Test;
    template<typename T, typename ...ARGS> 
    class Test<T(ARGS...)> {
    public:
        T operator()(ARGS... args) {
            return add<T, ARGS...>(args...);
        }

    private:
        template<typename T1, typename U, typename ... US>
        T1 add(U a, US ...args) {
            return a + add<T1>(args...);
        }
        template<typename T1, typename U>
        T1 add(U a) {
            return a;
        }
    };

    template<typename T, typename U>
    T test_param_func(U a) {
        return a * 2;
    }

    void func2(int (*func)(double)) {
        cout << func(2.3) << endl;
    }

    template<typename T> struct remove_reference { typedef T type; };

    template<typename T> struct remove_reference<T &> { typedef T type; };

    template<typename T> struct remove_reference<T &&> { typedef T type; };

    template<typename T>
    typename remove_reference<T>::type add2(T &&a, T &&b) {
        return a + b;
    };

    template<typename T> struct add_const { typedef const T type; };
    template<typename T> struct add_const<const T> { typedef const T type; };


    template<typename T> struct add_lvalue_reference { typedef T &type; };
    template<typename T> struct add_lvalue_reference<T &> { typedef T &type; };
    template<typename T> struct add_lvalue_reference<T &&> { typedef T &type; };


    template<typename T> struct add_rvalue_reference { typedef T &&type; };
    template<typename T> struct add_rvalue_reference<T &> { typedef T &&type; };
    template<typename T> struct add_rvalue_reference<T &&> { typedef T &&type; };


    template<typename T> struct remove_pointer { typedef T type; };
    template<typename T> struct remove_pointer<T *> { typedef typename remove_pointer<T>::type type; };

    template<typename T>
    typename add_rvalue_reference<T>::type move(T &&a) {
        return typename add_rvalue_reference<T>::type(a);
    }
}

void f(int &x) {
    cout << "f function: left reference" << endl;
}

void f(int &&x) {
    cout << "f function: right reference" << endl;
}


int main() {
    int a = 123, b = 456;
    f(a);
    f(move(a));
    cout << haizei::add2(a, b) << endl;
    cout << haizei::add2(haizei::move(a), haizei::move(b)) << endl;
    cout << haizei::add2(123, 456) << endl;
    haizei::func2(haizei::test_param_func);
    haizei::FoolPrintAny<string> f1;
    f1(string("hello world"));
    haizei::FoolPrintAny<int> f2;
    f2(123);
    int n = 45, m = 67;
    int *p = &n, *q = &m;
    cout << haizei::add(p, q) << endl;
    haizei::printAny(123, 34.5, "hello world");
    haizei::Test<int(int, int)> f3;
    cout << f3(10, 23) << endl;

    haizei::Test<int(int, int, int, int)> calculate;
    cout << calculate(100, 10000, 100000, 10) << endl;
    #if 0
    A a(1000);
    B b(500);
    cout << a + b << endl;
    cout << haizei::max(1, 3.6) << endl;
    cout << haizei::max("hello", "abc") << endl;
    cout << haizei::max(5.5, 9) << endl;
    haizei::PrintAny print1;
    print1(123);
    print1("hello world");
    print1(567.66);
    #endif
    #if 0
    haizei::PrintAny<int> print1;
    haizei::PrintAny<string> print2;
    print1(123);
    print1(4567);
    print2("hello world");
    print2("hello haizei");
    #endif
    #if 0
    cout << add(a, b) << endl;
    cout << add(1, 2) << endl;
    cout << add(2.3, 4.3) << endl;
    cout << add(2.3, 5) << endl;
    #endif
    return 0;
}
