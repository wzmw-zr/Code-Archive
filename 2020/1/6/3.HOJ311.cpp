/*************************************************************************
	> File Name: 3.HOJ311.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月06日 星期一 09时08分59秒
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
#define max_n 10000000
using namespace std;

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {
    is_prime[1] = 1;
    for (int i = 2; i <= max_n; i++) {
        if (is_prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    init();
   /* int n, count = 0;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) if (!is_prime[gcd(i, j)]) count++; 
    }
    cout << count << endl;
    */
    return 0;
}
