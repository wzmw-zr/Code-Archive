/*************************************************************************
	> File Name: 4.EP12.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月26日 星期四 19时31分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100000
using namespace std;

long prime[max_n + 5] = {0};
long f[max_n + 5] = {0};
long cnt[max_n + 5] = {0};

void init() {
    for (long i = 2; i <= max_n; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (long j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
            } else {
                f[i * prime[j]] = f[prime[j]] * f[i];
                cnt[prime[j] * i] = 1;
            }
        }
    }
}


int main() {
    init();
    long ans = 0, n = 2;
    while (ans <= 500 && (n++)) {
        if (n & 1) ans = f[n] * f[(n + 1) >> 1];
        else ans = f[n + 1] * f[n >> 1];
    }
    cout << (n * (n + 1) >> 1) << endl;
    return 0;
}
