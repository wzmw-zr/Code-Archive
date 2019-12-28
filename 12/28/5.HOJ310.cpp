/*************************************************************************
	> File Name: 5.HOJ310.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 14时05分53秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000000
using namespace std;

int prime[max_n + 5] = {0};
int num[max_n + 5] = {0};

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= n; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void get_val(int n) {
    for (int i = 1; i <= prime[0]; i++) {
        if (n == 1) break;
        while (n % prime[i] == 0) {
            num[i]++;
            n /= prime[i];
        }
    }
}

int main() {
    int n;
    cin >> n;
    init(n);
    for (int j = 1; j <= prime[0]; j++) {
        long temp = prime[j], count = 0;
        while (temp <= n) {
            count += n / temp;
            temp *= prime[j];
        }
        cout << prime[j] << " " << count << endl;
    }
    return 0;
}

