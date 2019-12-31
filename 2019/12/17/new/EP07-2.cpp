/*************************************************************************
	> File Name: EP07-2.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 19时09分29秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<inttypes.h>
#define MAX_N 200000
using namespace std;

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue; 
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }

    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
    }
    return ;
}


int main() {
    init();
    printf("%lld\n", prime[10001]);
    return 0;
}
