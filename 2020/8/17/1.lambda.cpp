/*************************************************************************
	> File Name: 1.lambda.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月17日 星期一 10时09分42秒
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

int mul(int a, int b) {
    return a * b;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    int n = 10000;
    auto a = [&n](int a, int b) -> double {
        double c = 12.3;
        if (rand() % 2) {
            return c;
        } else {
            return a + b;
        }
    };
    n = 1000000;
    auto b = [&n](int a, int b) {
        return a + b;
    };
    auto c = [](function<int(int, int)> a, function<int(int, int)> b) {
        return [=](int x) {
            return a(x, x) + b(x, x);
        };
    };
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << a(123, 456) << endl;
    cout << b(987, 120) << endl;
    auto d = c(a, b);
    cout << d(3) << endl;
    auto e = c(mul, add);
    return 0;
}
