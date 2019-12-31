/*************************************************************************
	> File Name: 6.prime.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 18时47分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<math.h>
#define max_n 1000000
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

int change(int n, int m) {
    int x = n / 10 + (n % 10) * pow(10, m - 1);
    //printf("%d\n", x);
    return x;
}

int is_val(int n) {
    int digit = floor(log10(n)) + 1;
    int m = digit;
    int flag = 0;
    while (digit) {
        if (prime[n]) {
            flag = 1;
            break;
        }
        n = change(n, m);
        digit--;
    }
    if (flag) return 0;
    return 1;
}

int main() {
    init();
    int count = 0;
    for (int i = 1; i < primes[0]; i++) {
        if (is_val(primes[i])) {
            printf("%d\n", primes[i]);
            count++;
        }
    } 
    printf("%d\n", count);
    return 0;
}
