/*************************************************************************
	> File Name: 6.EP39.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 15时07分49秒
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
#define max_n 1000

using namespace std;

int cnt[max_n + 5] = {0};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    for (int n = 1; n <= 33; n++) {
        for (int m = n + 1; m <= 33; m++) {
            if (gcd(m, n) - 1) continue;
            int a = 2 * n * m, b = m * m - n * n, c = m * m + n * n;
            for (int p = a + b + c; p <= 1000; p += a + b + c) {
                cnt[p]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= max_n; i++) {
        if (cnt[i] > cnt[ans]) ans = i;
    }
    cout << ans << endl;
    return 0;
}
