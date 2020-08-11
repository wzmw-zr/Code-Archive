/*************************************************************************
	> File Name: 2.constexpr.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月02日 星期日 19时00分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

constexpr int f(int x) {
    return 3 * x * x + x;
}

class A {
public :
    constexpr A(int x, int y) : x(x), y(y) {} 
    int x, y;
private :
};

int main() {
    int n;
    cin >> n;
    cout << f(5) << endl;
    constexpr int k = f(12);
    cout << k << endl;
    constexpr A a(2, 3);
    return 0;
}
