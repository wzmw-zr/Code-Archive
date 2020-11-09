/*************************************************************************
	> File Name: 1.large.number.add.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 22时17分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 100
using namespace std;


char str_a[max_n + 5] = {0}, str_b[max_n + 5] = {0};
int a[max_n + 5], b[max_n + 5];

void t_plus(int *a_1, int *b_1) {
    for (int i = 1; i <= b_1[0]; i++) {
        a_1[i] += b_1[i];
    }
    for (int i = 1; i <= a_1[0]; i++) {
        if (a_1[i] < 10) continue;
        a_1[i + 1] += a_1[i] / 10;
        a_1[i] %= 10;
        a_1[0] += (i == a_1[0]);
    }
    for (int i = a_1[0]; i >= 1; i--) {
        printf("%d", a_1[i]);
    }
    printf("\n");
    return ;
}

void add(char *str_a, char *str_b) {
    a[0] = strlen(str_a), b[0] = strlen(str_b);
    for (int i = 1; i <= strlen(str_a); i++) {
        a[a[0] - i + 1] = str_a[i - 1] - '0';
    }
    for (int i = 1; i <= strlen(str_b); i++) {
        b[b[0] - i + 1] = str_b[i - 1] - '0';
    }
    if (a[0] > b[0]) t_plus(a, b);
    else t_plus(b, a);
    return ;
}

int main() {
    scanf("%s%s", str_a, str_b);
    add(str_a, str_b);
    return 0;
}
