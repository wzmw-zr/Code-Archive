/*************************************************************************
	> File Name: 6.T1817.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月04日 星期六 09时48分03秒
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
    cout << n << "=";
    int x = n;
    int flag = 0;
    for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= x; i++) {
        if (n % prime[i]) continue;
        while (n % prime[i] == 0) {
            flag == 0 && cout << prime[i];
            flag && cout << "*" << prime[i];
            flag++;
            n /= prime[i];
        }
    }
    if (n > 1) {
        flag == 0 && cout << n << endl;
        flag && cout << "*" << n <<endl;
    }
    else cout << endl;
    return 0;
}
