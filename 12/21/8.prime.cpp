/*************************************************************************
	> File Name: 8.prime.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 19时41分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define max_n 8000000
using namespace std;

int prime[max_n + 5] = {0};
int primes[max_n + 5] = {0};


void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) primes[++primes[0]] = i;
        for (int j = 1; j <= primes[0] && i * primes[j] <= max_n; j++) {
            prime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}


int main() {
    init();
    int n, count = 0;
    //for (int i = 1; i<=primes[0]; i++) {
      //  printf("%d\n", primes[i]);
    //}
    scanf("%d", &n);
    for (int i = 1; i <= primes[0] && primes[i] < n; i++) {
        if (prime[n - primes[i]] == 1) continue;
        if (n - primes[i] < primes[i]) break;
        count++;
    }
    printf("%d\n", count);
    return 0;
}


