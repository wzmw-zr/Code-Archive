/*************************************************************************
	> File Name: 6.large.divise.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月05日 星期日 20时39分33秒
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
    int len_a = strlen(str_a), len_b = strlen(str_b);
    for (int i = 0; i < len_a; i++) a[i] = str_a[len_a - i - 1] - '0';
    for (int i = 0; i < len_b; i++) b[i] = str_b[len_b - i - 1] - '0';
    
    return 0;
}
