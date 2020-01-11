/*************************************************************************
	> File Name: 5.large.minus.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月05日 星期日 18时38分55秒
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

char str_a[max_n + 5], str_b[max_n + 5];
int a[max_n + 5] = {0}, b[max_n + 5] = {0}, res[max_n + 5] = {0};

int main() {
    scanf("%s%s", str_a, str_b);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int len_a = strlen(str_a), len_b = strlen(str_b);
    if (len_a < len_b || len_a == len_b && strcmp(str_a, str_b) < 0) {
        char temp[max_n + 5] = {0};
        strcpy(temp, str_a);
        strcpy(str_a, str_b);
        strcpy(str_b, temp);
        len_a = strlen(str_a);
        len_b = strlen(str_b);
        printf("-");
    }
    for (int i = 0; i < len_a; i++) a[i] = str_a[len_a - i - 1] - '0';
    for (int i = 0; i < len_b; i++) b[i] = str_b[len_b - i - 1] - '0';
    for (int i = 0; i < len_a; i++) {
        if (a[i] < b[i]) a[i] += 10, a[i + 1]--;
        a[i] -= b[i];
    }
    int index = len_a;
    while (!a[index]) index--;
    for (int i = index; i >= 0; i--) printf("%d", a[i]);
    printf("\n");
    return 0;
}
