/*************************************************************************
	> File Name: 2.va.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月03日 星期五 20时57分40秒
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
#define max_n 100
using namespace std;

char character[max_n + 5] = {0};

void print(int n, ...) {
    va_list arg;
    va_start(arg, n);
    for (int i = 1; i <= n; i++) {
        int c = va_arg(arg, int);
        printf("%d", c);
    }
    va_end(arg);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    print(n, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    return 0;
}
