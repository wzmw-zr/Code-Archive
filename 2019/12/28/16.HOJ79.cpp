/*************************************************************************
	> File Name: 16.HOJ79.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 23时38分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10000000
using namespace std;

int prime[max_n + 5] = {1, 1, 0};
int primes[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) primes[++primes[0]] = i;
        for (int j = 1; j <= primes[j] && i * primes[j] <= max_n; j++) {
            prime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    init();
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) !prime[i] && printf("%d\n", i);
    return 0;
}
