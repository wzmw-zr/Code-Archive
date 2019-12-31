/*************************************************************************
	> File Name: prime.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月19日 星期四 19时13分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define MAX_N 1000000
using namespace std;

int prime[MAX_N + 5] = {0};
int primes[MAX_N] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] == 0) primes[++primes[0]] = i;
        for (int j = 1; j <= primes[0] && i * primes[j] <= MAX_N; j++) {
            prime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}


int main() {
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = m; i <= n; i++) {
        printf("%d ", prime[i]);
        if (prime[i] != 1) printf("%d\n", i);

    }
    return 0;
}
