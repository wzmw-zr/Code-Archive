/*************************************************************************
	> File Name: 6.prime.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 20时49分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<ctsirng>
#define max_n 1000
using namespace std;

int prime[max_n + 5] = {0};

void init_prime() {
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i < max_n; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j < max_n; j += i) {
            prime[j] = 1;
        }
    }
}


int prime_1(int n) {
    if (n <= 1) return 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 1;
    }
    return 0;
}

int main () {
    int n;
    init_prime();
    while (~scanf("%d", &n)) {
        printf("%s\n", prime[n] ? "NO" : "YES");
    }
    return 0;
}
