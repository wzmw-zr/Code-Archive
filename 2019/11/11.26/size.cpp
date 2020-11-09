/*************************************************************************
	> File Name: size.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 01时07分30秒
 ************************************************************************/

#include<stdio.h>

int main () {
    char c;
    scanf("%c", &c);
    double m, n;
    scanf("%lf%lf", &m, &n);
    c == 'r' ? printf("%.2lf", m * n) : printf("%.2lf", (m * n) / 2);
    return 0;
}
