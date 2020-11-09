/*************************************************************************
	> File Name: 4.divide.fac.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 23时27分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000000
using namespace std;

long prime[max_n + 5] = {0};
long num[max_n + 5] = {0};

void init() {
    for (long i = 2; i <= max_n; i++) {
        if (prime[i] == 0) prime[++prime[0]] = i;
        for (long j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve(long n) {
    for (long i = 1; i <= prime[0]; i++) {
        if (n == 1) break;
        while (n % prime[i] == 0) {
            n /= prime[i];
            num[i]++;
        }
    } 
}

int main() {
    init();
    long n; 
    scanf("%lld", &n);
    long x = n;
    while (n > 1) {
        solve(n);
        n--;
    }
    //for (int i = 1; i <= n; i++) {
      //  printf("%d %d\n", prime[i], )
    //}
    for (long i = 1; i <= (long) sqrt(n); i++) {
        if (num[i]) printf("%lld %lld\n", prime[i], num[i]);
    }
    return 0;
}
