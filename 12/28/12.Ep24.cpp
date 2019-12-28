/*************************************************************************
	> File Name: 12.Ep24.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 19时18分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10
using namespace std;

int fac[max_n + 5] = {0};
int num[max_n + 5] = {0};

void init(int n) {
    fac[0] = 1;
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    }
}

int get_num(int k, int n, int &x) {
    int step = k / n, t;
    x = 0;
    for (t = 0; t <= step; x += (t <= step)) {
        t += num[x];
    }
    k %= n;
    num[x] = 0;
    return k;
}

int main() {
    init(10);
    int k = 1000000 - 1;
    for (int i = max_n; i > 0; i--) {
        int x;
        k = get_num(k, fac[i - 1], x);
        cout << x;
    }
    cout << endl;
    return 0;
}
