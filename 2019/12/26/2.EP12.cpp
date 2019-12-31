/*************************************************************************
	> File Name: 2.EP12.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月26日 星期四 16时01分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000000
using namespace std;

long prime[max_n + 5] = {0};
long f[max_n + 5] = {0};
long l[max_n + 5] = {0};

void init() {
    for (long i = 2; i <= max_n; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
            f[i] = 2;
            l[i] = 1;
        }
        for (long j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] * (l[i] + 2) / (l[i] + 1);
                l[i * prime[j]] = l[i] + 1;
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                l[i * prime[j]] = 1;
            }
        }
    }
}

int main() {
    init();
    long n = 2, f_max = 0;
    while (1) {
        if (n & 1) f_max = f[n] * f[(n + 1) >> 1];
        else f_max = f[n >> 1] * f[n + 1];
        if (f_max > 500) break;
        n++;
    }
    printf("%lld\n", n);
    printf("%lld\n", n * (n + 1) >> 1);
    //while (f[n * (n + 1) >> 1] <= 500) n++;
    //printf("%d\n", n * (n + 1) >> 1);
    //printf("%d\n", f[n * (n + 1) >> 1]);
    return 0;
}
