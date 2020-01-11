/*************************************************************************
	> File Name: 5.T1683.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月04日 星期六 09时34分42秒
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
#define max_n 100000
using namespace std;

int prime[max_n + 5] = {0};
int number[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= prime[0]; i++) {
        int p = prime[i], num = 0;
        while (p <= n) {
            num += n / p;
            p *= prime[i];
        }
        number[i] = num;
    }
    for (int i = 1; i <= prime[0]; i++) {
        number[i] && (cout << prime[i] << " " << number[i] << endl);
    }
    return 0;
}
