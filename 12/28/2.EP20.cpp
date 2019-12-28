/*************************************************************************
	> File Name: 2.EP20.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 09时51分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 300
using namespace std;

int num[max_n + 5] = {0};

int main() {
    num[0] = 1, num[1] = 1;
    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j <= num[0]; j++) num[j] *= i;
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= num[0]; i++) sum += num[i];
    cout << sum << endl;
    return 0;
}
