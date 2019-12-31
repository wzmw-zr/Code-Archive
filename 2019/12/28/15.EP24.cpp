/*************************************************************************
	> File Name: 15.EP24.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 23时12分45秒
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

void init() {
    fac[0] = 1, num[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    }
    return ;
}

int get_num(int n, int k) {
    int p = fac[n - 1], step = k / p, index = 0, i;
    for (i = step; i >= 0; index += (i >= 0)) {
        i -= num[index];
    }
    num[index] = 0;
    return index;
}

int main() {
    init();
    int k = 1000000 - 1;
    for (int i = max_n; i >= 1; i--) {
        cout << get_num(i, k);
        k %= fac[i - 1];
    }
    cout << endl;
    return 0;
}
