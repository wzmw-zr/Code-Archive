/*************************************************************************
	> File Name: 3.large.mul.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月05日 星期日 16时38分16秒
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
int res[max_n + 5] = {0};
char num[max_n + 5] = {0};

int main() {
    scanf("%s", num);
    int len = strlen(num);
    num1[0] = len;
    for (int i = 1; i <= len; i++) {
        num1[i] = num[len - i] - '0'; 
    }
    memset(num, 0, sizeof(num));
    scanf("%s", num);
    len = strlen(num);
    num2[0] = len;
    for (int i = 1; i <= len; i++) {
        num2[i] = num[len - i] - '0';
    }
    res[0] = max(num1[0], num2[0]);
    for (int i = 1; i <= num1[0]; i++) {
        for (int j = 1; j <= num2[0]; j++) {
            res[i + j - 1] += num1[i] * num2[j];
        }
        for (int j = 1; j <= res[0]; j++) {
            if (res[j] < 10) continue;
            res[j + 1] += res[j] / 10;
            res[j] %= 10;
            res[0] += (j == res[0]);
        }
    }
    for (int i = res[0]; i >= 1; i--) printf("%d", res[i]);
    printf("\n");
    return 0;
}
