/*************************************************************************
	> File Name: 4.prime.factor.number.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月06日 星期一 10时19分52秒
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
#include<ctime>
#define max_n 1000000
using namespace std;

int prime[max_n + 5] = {0};
int min_n[max_n + 5] = {0};
int num[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
            num[i] = 2;
            min_n[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] != 0) {
                num[i * prime[j]] = num[i] * num[prime[j]];
                min_n[i * prime[j]] = 1;
            } else {
                num[i * prime[j]] = num[i] * (min_n[i] + 2) / (min_n[i] + 1);
                min_n[i * prime[j]] = min_n[i] + 1;
            }
        }
    }
    return ;
}

int main() {
    init();
    return 0;
}
