/*************************************************************************
	> File Name: 1.EP29.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 09时29分36秒
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
#define max_l 200
using namespace std;

int num[max_n + 5][max_l + 5];
int count = 0;
int temp[max_l] = {0};

void get_val(int a, int b) {
    memset(temp, 0, sizeof(temp));
    temp[0] = 1, temp[1] = 1;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= temp[0]; j++) {
            temp[j] *= a;
        }
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[i] / 10;
            temp[i] %= 10;
            temp[0] += (j == temp[0]); 
        }
    }

}

int is_exist() {
    for (int i = 0; i < count; i++) {
        if (memcmp(num + i, temp, sizeof(max_l))) continue;
        return 1;
    }
    return 0;
}
int main() {
    memset(num, 0, sizeof(num));
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            get_val(i, j);
            if (is_exist()) continue;
            memcpy(num + count, temp, sizeof(max_l));
            count++;
        }
    }
    cout << count;
    return 0;
}
