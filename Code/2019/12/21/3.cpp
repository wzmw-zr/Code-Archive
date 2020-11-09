/*************************************************************************
	> File Name: 3.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 11时03分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define max_n 100000
using namespace std;

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j]) break;
        }
    }
}


int main() {
    init();
    for (int i = 2; i <= 100; i++) {
        printf("%d ", prime[i]);
    }
    printf("\n");
    return 0;
}
