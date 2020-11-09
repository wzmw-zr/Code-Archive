/*************************************************************************
	> File Name: shortest_length.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 00时03分38秒
 ************************************************************************/

#include<stdio.h>

int main () {
    double a, v, length;
    scanf("%lf%lf", &v, &a);
    length = (v * v) / (2 * a);
    printf("%.2lf", length);
    return 0;
}
