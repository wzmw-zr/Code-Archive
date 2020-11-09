/*************************************************************************
	> File Name: dump_in_water.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 00时39分54秒
 ************************************************************************/

#include<stdio.h>

int main () {
    double a, b, c, t;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &t);
    printf("%.2lf", (1 - (1 / a + 1 / b) * t) / (1 / a + 1 / b - 1 / c)  + t);
    return 0;
}
