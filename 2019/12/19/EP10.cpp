/*************************************************************************
	> File Name: EP10.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月19日 星期四 18时47分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<inttypes.h>
#define MAX_N 2000000
using namespace std;

int prime[MAX_N + 5] = {0};

long long init() {
    long long sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
            sum += i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return sum;
}

int main() {
    long long result = init();
    printf("%lld", result);
    return 0;
}
