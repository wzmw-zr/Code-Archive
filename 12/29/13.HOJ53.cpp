/*************************************************************************
	> File Name: 13.HOJ53.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 20时12分13秒
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

int prime[max_n + 5] = {0};
long f[max_n + 5] = {0};
long l[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
            f[i] = 1 + i;
            l[i] = i * i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                f[i * prime[j]] = f[i] * f[prime[j]];
                l[i * prime[j]] = prime[j] * prime[j];
            } else {
                f[i * prime[j]] = f[i] * (l[i] * prime[j] - 1) / (l[i] - 1);
                l[i * prime[j]] = l[i] * prime[j];
            break;
            }
        }
    }
}

int main() {
    init();
    long ans = 0;
    for (int i = 2; i <= max_n; i++) {
        if (f[i] <= ans) continue;
        ans = f[i];
    }
    cout << ans << endl;
    return 0;
}
