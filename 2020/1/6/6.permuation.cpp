/*************************************************************************
	> File Name: 6.permuation.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月06日 星期一 17时12分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 10
using namespace std;

int fac[max_n + 5] = {0}, num[max_n + 5] = {0};

void init() {
    fac[0] = 1, num[0] = 1;
    for (int i = 1; i <= 10; i++) fac[i] = i * fac[i - 1], num[i] = 1;
}

int get_number(int p, int n, int &x) {
    int t, step = n / fac[p - 1];
    x = 0;
    for (t = 0; t <= step; x += (t <= step)) t += num[x];
    n %= fac[p - 1];
    num[x] = 0;
    return n;
}

int main() {
    init();
    int n; 
    cin >> n;
    n--;
    for (int i = 10; i >= 1; i--) {
        int x;
        n = get_number(i, n, x);
        cout << x;
    }
    cout << endl;
    return 0;
}
