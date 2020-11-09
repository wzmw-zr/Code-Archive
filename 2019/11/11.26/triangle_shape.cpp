/*************************************************************************
	> File Name: triangle_shape.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 22时03分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;


void decrease(int &a, int &b, int &c) {
    if (a <= b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b <= c) {
        if (a <= c) {
            int temp = a;
            a = c;
            c = b;
            b = temp;
        }else {
            int temp = b;
            b = c;
            c = temp;
        }
    }
}

int main () {
    int a, b, c;
    cin >> a >> b >> c;
    decrease(a, b, c);
    if (a >= b + c) {
        cout << "illegal triangle";
        return 0;
    }
    if (b * b + c * c > a * a) cout << "acute triangle";
    else if (b * b + c * c < a * a) cout << "obtuse triangle";
    else cout << "right triangle";
    return 0;
}
