/*************************************************************************
	> File Name: 9.EP46.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 15时51分56秒
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
int primes[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) primes[++primes[0]] = i;
        for (int j = 1; j <= primes[0] && i * primes[j] <= max_n; j++) {
            prime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int is_sqrt(int n) {
    return 2 * n * n;
}

bool binary_search(int (*func)(int), int l, int r, int x) { 
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return true;
    if (func(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(func, l, r, x);
}

bool check(int n) {
    int flag = 0;
    for (int j = 1; j <= primes[0] && primes[j] < n; j++) {
        if (binary_search(is_sqrt, 1, n - primes[j], n - primes[j]))return true; 
    }
    return false;
}

int main() {
    init();
    int ans = 0;
    for (int i = 9; i <= max_n; i += 2) {
        if (!prime[i]) continue;
        if (check(i)) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}
