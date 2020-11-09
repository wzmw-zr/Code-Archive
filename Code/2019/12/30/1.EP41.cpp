/*************************************************************************
	> File Name: 1.EP41.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月30日 星期一 20时33分44秒
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
#define max_n 100000000
using namespace std;

long prime[max_n + 5] = {0};

void init() {
    for (long i = 2; i <= max_n; i++) {
        if (prime[i] == 0) prime[++prime[0]] = i;
        for (long j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_val(int n) {
    int num[10] = {0};
    num[0] = 1;
    int digit = floor(log10(n)) + 1;
    while (n) {
        if (num[n % 10]) return 0;
        num[n % 10] = 1;
        n /= 10;
    }
    for (int i = 1; i <= digit; i++) {
        if (num[i]) continue;
        return 0;
    } 
    return 1;
}

int main() {
    init();
    long ans;
    for (int i = 1; i <= prime[0]; i++) {
        if (!is_val(prime[i])) continue;
        ans = prime[i];
    }
    cout << ans << endl;
    return 0;
}
