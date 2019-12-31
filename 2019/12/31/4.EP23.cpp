/*************************************************************************
	> File Name: 2.EP23.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月31日 星期二 08时48分43秒
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
#define max_n 28123
using namespace std;

long prime[max_n + 5] = {0};
long factor_sum[max_n + 5] = {0};
long min_factor_pow[max_n + 5] = {0};
long is_abundant[max_n + 5] = {0};

void init() {
    for (long i = 2; i <= max_n; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
            factor_sum[i] = 1 + i;
            min_factor_pow[i] = i * i;
        }
        for (long j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                factor_sum[i * prime[j]] = factor_sum[i] * (min_factor_pow[i] * prime[j] - 1) / (min_factor_pow[i] - 1);
                min_factor_pow[i * prime[j]] = min_factor_pow[i] * prime[j];
                break;
            } else {
                factor_sum[i * prime[j]] = factor_sum[i] * factor_sum[prime[j]];
                min_factor_pow[i * prime[j]] = prime[j] * prime[j];
            }
        }
    }
}

int is_val(long n) {
    for (long i = 12; i <= n - 12; i++) {
        if (!is_abundant[i] || !is_abundant[n - i]) continue;
        return 1;
    }
    return 0;
}

int main() {
    init();
    int cnt = 0;
    for (int i = 0; i <= max_n; i++) {
        factor_sum[i] -= i;
        if (factor_sum[i] > i) factor_sum[++factor_sum[0]] = i;
    }
    for (int i = 1; i <= factor_sum[0]; i++) {
        for (int j = i; j <= factor_sum[0]; j++) {
            if (factor_sum[i] + factor_sum[j] > max_n) break;
            is_abundant[factor_sum[i] + factor_sum[j]] = 1;
        }
    }
    for (long i = 0; i <= max_n; i++) {
        if (!is_abundant[i]) cnt += i;
    }
    cout << cnt <<endl;
    return 0;
}
