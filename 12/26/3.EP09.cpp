/*************************************************************************
	> File Name: 3.EP09.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月26日 星期四 18时04分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;


int gcd(int a, int b) {
    return b ? gcd(b , a % b) : a;
}


int main() {
    int ans = 0;
    for (int n = 1; n <= 23; n++) {
        for (int m = n + 1; m * m + n * n < 1000; m++) {
            if (gcd(m, n) - 1) continue;
            int a = 2 * n * m, b = m * m - n * n, c = m * m + n * n;
            if (1000 % (a + b + c)) continue;
            ans  = a * b * c * pow(1000 / (a + b + c), 3);
            if (ans) break;
        }
        if (ans) break;
    }
    cout << ans << endl;
    return 0;
}
