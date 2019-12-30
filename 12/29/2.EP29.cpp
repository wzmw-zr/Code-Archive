/*************************************************************************
	> File Name: 2.EP29.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 10时13分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10000
#define max_m 210
using namespace std;

int num[max_n][max_m];
int len = 0;

void large_mul(int *temp, int a, int b) {
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
}

int is_exist(int *temp) {
    for (int i = 0; i < len; i++) {
        if (memcmp(num + i, temp, sizeof(int) * max_m)) continue;
        return 1;
    }
    return 0;
}

int main() {
    memset(num, 0, sizeof(num));
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            int temp[max_m] = {0};
            large_mul(temp, i, j);
            if (is_exist(temp)) continue;
            memcpy(num + len, temp, sizeof(int) * max_m);
            len++;
        }
    }
    cout << len <<endl;
    return 0;
}
