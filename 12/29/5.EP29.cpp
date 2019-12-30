/*************************************************************************
	> File Name: 5.EP29.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 14时05分43秒
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
#define max_n 10000
#define max_l 210
using namespace std;

int *num[max_n + 5];
int len = 0;

int *large_mul(int a, int b) {
    int *temp = (int *)calloc(sizeof(int), max_l);
    temp[0] = 1, temp[1] = 1;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= temp[0]; j++) temp[j] *= a;
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (j == temp[0]);
        }
    }
    return temp;
}

int is_exist(int *temp) {
    for (int i = 0; i < len; i++) {
        if (!memcmp(num[i], temp, sizeof(int) * max_l)) return 1;
    }
    return 0;
}

int main() {
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int *temp = large_mul(a, b);
            if (!is_exist(temp)) {
                num[len++] = temp;
            }
        }
    } 
    cout << len << endl;
    return 0;
}
