/*************************************************************************
	> File Name: 3.EP50.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月01日 星期三 10时16分25秒
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

int main() {
    init();
    int res = 0, max_len = 0;
    for (int i = 1; i <= prime[0]; i++) {
        int sum = prime[i], len = 1;
        for (int j = i + 1; j <= prime[0]; j++) {
            sum += prime[j];
            if (sum >= max_n) {
                sum -= prime[j];
                break;
            }
            if (is_prime[sum]) continue;
            len = j - i + 1;
        }
        if (max_len >= len) continue;
        max_len = len, res = sum;
    }
    cout << res << endl;
    return 0;
}
