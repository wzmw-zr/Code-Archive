/*************************************************************************
	> File Name: 4.template_turing.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月31日 星期五 16时00分39秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<int x>
struct isOdd {
    constexpr static int r = x % 2;
};

template<int i, int x>
struct getNextK {
    constexpr static int r = (i * i > x ? 0 : (x % i == 0 ? 1 : 2));
};

template<int i, int x, int k>
struct Test {
    constexpr static int r = Test<i + 1, x, getNextK<i, x>::r >::r;
};


template<int i, int x>
struct Test<i, x, 0> {
    constexpr static int r = 1;
};

template<int i, int x>
struct Test<i, x, 1> {
    constexpr static int r = 0;
};


template<int x>
struct is_prime {
    constexpr static int r = Test<2, x, 2>::r;
};

bool __is_prime_1(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool __is_prime(int i, int x) {
    if (i * i > x) return true;
    if (x % i == 0) return false;
    return __is_prime(i + 1, x);
}

bool is_prime_1(int x) {
    return __is_prime(2, x);
}

int main() {
    cout << isOdd<5>::r << endl;
    cout << isOdd<6>::r << endl;
    cout << is_prime<9973>::r << endl;
    cout << is_prime<10000>::r << endl;
    return 0;
}
