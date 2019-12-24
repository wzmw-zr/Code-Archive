/*************************************************************************
	> File Name: 1.EP38.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 09时44分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 100000
using namespace std;

long digit(long x) {
    return floor(log10(x)) + 1;
}

int legal(long x) {
    int num[10] = {0};
    num[0] = 1;
    while (x) {
        if (num[x % 10]) return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

long add(long x, long y) {
    long dig = digit(x * y);
    return x * (long)pow(10, dig) + x * y;
}

long calc(long x) {
    long ans = x, n = 2;
    while (digit(ans) < 9) {
        ans = add(ans, n);
        n++;
    }
    if (digit(ans) - 9) return 0;
    if (!legal(ans)) return 0;
    return ans;
}

int main() {
    long ans = 0, temp;
    for (long i = 1; i < max_n; i++) {
        temp = calc(i);
        if (!temp) continue;
        if (temp <= ans) continue;
        ans = temp;
    }
    printf("%lld", ans);
    return 0;
}
