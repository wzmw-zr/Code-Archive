/*************************************************************************
	> File Name: 7.EP37.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 19时44分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<math.h>
#define max_n 1000000
using namespace std;

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};



void init() {
    is_prime[0] = 1, is_prime[1] = 1;
    for (int i = 2; i <= max_n; i++) {
        if (is_prime[i] == 0) prime[++prime[0]] = i;
        for (int j  = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_val(int n) {
    int x = n;
    while (x) {
        if (is_prime[x]) return 0;
        x /= 10;
    }
    int digit  = floor(log10(n)) + 1;
    x = n;
    while (x) {
        if (is_prime[x]) return 0;
        int p = pow(10, digit - 1);
        x %= p;
        digit--;
    }
    return 1;
}

int main() {
    init();
    int count = 0, sum = 0;
    for (int i = 5; i <= prime[0] && count < 11; i++) {
        if (!is_val(prime[i])) continue;
        count++; 
        sum += prime[i];
    }
    printf("%d\n", sum);
    return 0;
}
