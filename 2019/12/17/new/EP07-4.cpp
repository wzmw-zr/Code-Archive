/*************************************************************************
	> File Name: EP07-4.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 20时01分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define MAX_N 200000
using namespace std;

int prime[MAX_N + 5]  ={0};

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j < MAX_N; j += i) {
            prime[j] = i;
        }
    }
}

int main() {
    init();
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", prime[n]);
    }
    return 0;
}
