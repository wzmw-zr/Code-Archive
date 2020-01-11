/*************************************************************************
	> File Name: 2.test.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月10日 星期五 19时38分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int f(int n) {
    if (n == 1) return 1;
    return n * f(n - 1);
}

int main() {
    int n; 
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
