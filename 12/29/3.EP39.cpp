/*************************************************************************
	> File Name: 3.EP39.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 10时54分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 33
#define max_m 1000
using namespace std;

int num[max_m + 5] = {0};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int count = 0;
    int max_num = 0, index;
    for (int m = 2; m <= max_n; m++) {
        for (int n = 1; n <= m; n++) {
            if (gcd(m, n) - 1) continue;
            int a = 2 * m * n, b = m * m - n * n, c = m * m + n * n;
            for (int i = a + b + c; i <= 1000; i += (a + b + c)) num[i]++;
        }
    }
    for (int i = 1; i <= max_m; i++) {
        if (num[i] <= max_num) continue;
        max_num = num[i];
        index = i;
    }
    cout << index << endl;
}
