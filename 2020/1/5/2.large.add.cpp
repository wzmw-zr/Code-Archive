/*************************************************************************
	> File Name: 2.large.add.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月05日 星期日 16时15分21秒
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
#define max_n 1000
using namespace std;

int num1[max_n + 5] = {0};
int num2[max_n + 5] = {0};
char num[max_n + 5] = {0};

int main() {
    scanf("%s", num);
    int len = strlen(num);
    num1[0] = len;
    for (int i = 0; i < len; i++) {
        num1[i + 1] = num[len - i - 1] - '0';
    }
    memset(num, 0, sizeof(num));
    scanf("%s", num);
    len = strlen(num);
    num2[0] = len;
    for (int i = 0; i < len; i++) {
        num2[i + 1] = num[len - i - 1] - '0';
    }
    num1[0] = num1[0] > num2[0] ? num1[0] : num2[0];
    for (int i = 1; i <= num1[0]; i++) {
        num1[i] += num2[i];
    }
    for (int i = 1; i <= num1[0]; i++) {
        if (num1[i] < 10) continue;
        num1[i + 1] += num1[i] / 10;
        num1[i] %= 10;
        num1[0] += (i == num1[0]);
    }
    for (int i = num1[0]; i >= 1; i--) {
        printf("%d", num1[i]);
    }
    printf("\n");
    return 0;
}
