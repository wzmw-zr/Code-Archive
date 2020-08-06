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

    template<typename T, typename ...ARGS> class ARG;
    template<typename T, typename ...ARGS>
    class ARG {
    public:
        typedef T __type;
        typedef ARG<ARGS...> __rest;
    };

    template<typename T>
    class ARG<T>{
    public:
        typedef T __type;
    };

    template<typename T, typename ...ARGS> class Test;
    template<typename T, typename ...ARGS> 
    class Test<T(ARGS...)> {
    public:
        T operator()(
            typename ARG<ARGS...>::__type a,
            typename ARG<ARGS...>::__rest::__type b
        ) {
                return a + b;
        }
    };

}

int main() {
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
