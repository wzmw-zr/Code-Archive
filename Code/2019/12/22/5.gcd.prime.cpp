/*************************************************************************
	> File Name: 5.gcd.prime.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 00时03分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 10000000
using namespace std;

int is_prime[max_n + 5] = {0};
int prime[max_n + 5] = {0};

void init() {
    is_prime[1] = 1;
    for (int i = 2; i <= max_n; i++) {
        if (is_prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

int main() {
    init();
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            int x = gcd(i, j);
            //printf("gcd(%d, %d) = %d\n", i, j, x);
            //printf("is_prime[%d] = %d\n", x, is_prime[x]);
            if (is_prime[x]) continue;
            //printf("%d, %d\n", i, j);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
