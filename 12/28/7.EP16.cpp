/*************************************************************************
	> File Name: 7.EP16.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 15时50分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 400
using namespace std;

int num[max_n + 5] = {0};

int main() {
    num[0] = 1, num[1] = 1;
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= num[0]; j++) num[j] *= 1024;
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    for (int i = 1; i <= num[0]; i++) sum += num[i];
    cout << sum << endl;
    return 0;
}
