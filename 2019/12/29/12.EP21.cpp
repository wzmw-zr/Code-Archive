/*************************************************************************
	> File Name: 12.EP21.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 18时30分33秒
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
#define max_n 1000000
using namespace std;

long prime[max_n + 5] = {0};
long f[max_n + 5] = {0};
long cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
            f[i] = 1 + i;    
            cnt[i] = i * i;
        }
        for (int j = 1; j <= prime[0] &&  i * prime[j] <= max_n; j++) {
            prime[i * prime[j]]  = 1;
            if (i % prime[j]) {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = prime[j] * prime[j];
            } else {
                f[i * prime[j]] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1);
                cnt[i * prime[j]] = cnt[i] * prime[j];
                break;
            }
        }
    }
}

int main() {
    init();
    long sum = 0;
    for (int i = 2; i < max_n; i++) {
        f[i] -= i;
    }
    for (int i = 2; i < max_n; i++) {
        if (f[i] != i && f[i] < max_n && i == f[f[i]]) sum += i;
    }
    cout << sum << endl;
    return 0;
}
