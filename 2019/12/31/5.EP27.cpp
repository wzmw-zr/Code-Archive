/*************************************************************************
	> File Name: 5.EP27.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月31日 星期二 14时21分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 2010
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

int if_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i) continue;
        return 0;
    }
    return 1;
}

int get_max_n(int a, int b) {
    int i, flag = 1;
    for (i = 0; flag; i++) {
        if (i * i + a * i + b <= 1) return i;
        if (if_prime(i * i + a * i + b)) continue;
        cout << i << endl;
        return i;
    }
    return i - 1;
}

int main() {
    init();
    int a = 0, b = 0, ans = 0;
    int x, y;
    for (int i = 1; i <= prime[0]; i++) {
        b = prime[i];
        if (b - 1000 > 0) break;
        for (a = -999; a < 1000; a++) {
            if (a + b + 1 <= 1) continue;
            if (is_prime[a + b + 1]) continue;
            int times = get_max_n(a, b);
            if (ans >= times) continue;
            ans = times;
            x = a; 
            y = b;
        }
    }
    cout << ans << endl;
    cout << x << " " << y << endl;
    cout << x * y << endl;
    return 0;
}
