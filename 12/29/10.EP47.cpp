/*************************************************************************
	> File Name: 10.EP47.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 16时53分50秒
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
#define max_n 1000000
using namespace std;

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (is_prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_val(int n) {
    int cnt = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (n == 1) break;
        if (n % prime[i]) continue;
        while (n % prime[i] == 0) {
            n /= prime[i];
        }
        cnt++;
    }
    return cnt == 4;
}

int main() {
    init();
    for (int i = 1000; i <= max_n; i++) {
        if (is_val(i) && is_val(i + 1) && is_val(i + 2) && is_val(i + 3)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
