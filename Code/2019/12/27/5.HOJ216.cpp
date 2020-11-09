/*************************************************************************
	> File Name: 5.HOJ216.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 14时28分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100
#define max_l 50
using namespace std;

char origin_name[max_n + 5][max_l + 5] = {0};
char re_name[max_n + 5][max_l + 5] = {0};

void change(int n) {
    for (int i = 1; i <= n; i++) {
        int len = strlen(origin_name[i]);
        for (int j = 3; j <= len; j++) re_name[i][j - 3] = origin_name[i][j];
    }
}

void sort_name(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            char temp[max_l + 5] = {0};
            if (strcmp(re_name[j], re_name[j + 1]) <= 0) continue;
            strcpy(temp, re_name[j]);
            strcpy(re_name[j], re_name[j + 1]);
            strcpy(re_name[j + 1], temp);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", origin_name[i]);
    change(n);
    sort_name(n);
    for (int i = 1; i <= n; i++) {
        i == n && printf("%s", re_name[i]);
        i != n && printf("%s\n", re_name[i]);
    }
    return 0;
}
