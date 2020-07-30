/*************************************************************************
	> File Name: 1.variable_template.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月30日 星期四 08时00分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

template<typename T>
void print(const T a) {
    cout << a << endl;
    return ;
}

template<typename T, typename... ARGS>
void print(const T a, ARGS... args) {
    print(args...);
    return ;
}


template<typename T, typename... ARGS>
struct ARG {
    typedef T getT; 
    typedef ARG<ARGS...> rest;
};

template<typename T>
struct ARG<T> {
    typedef T getT; 
};

template<typename First, typename... ARGS> 
class Test;

template<typename First, typename... ARGS>
class Test<First(ARGS...)> {
public:
    First operator()(typename ARG<ARGS...>::getT a, typename ARG<ARGS...>::rest::getT b) {
        return a + b;
    }
};


int main() {
    print(100, 10.3, "hello world", 'o');
    cout << sizeof(ARG<int, double, float>::getT) << endl;
    cout << sizeof(ARG<int, double, float>::rest::getT) << endl;
    cout << sizeof(ARG<int, double, float>::rest::rest::getT) << endl;
    ARG<int, double, float>::getT a = 123;
    ARG<int, double, float>::rest::getT b = 12.3;
    ARG<int, double, float>::rest::rest::getT c = 123.45;
    cout << a << " " << b << " " << c << endl;
    Test<int(double, float)> d;
    cout << d(1, 3) << endl;
    return 0;
}
