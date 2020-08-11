/*************************************************************************
	> File Name: 4.nullptr.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月02日 星期日 20时07分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

int f(int x) {
    cout << "output int value : ";
    cout << x << endl;
    return 0;
}

int f(int *x) {
    cout << "output address : " ;
    cout << x << endl;
    return 0;
}

int main() {
    int n = 123, *p = &n;
    f(n);
    f(p);
    f(nullptr);
    return 0;
}
