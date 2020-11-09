/*************************************************************************
	> File Name: taxi_cost.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 01时20分55秒
 ************************************************************************/

#include<stdio.h>

int main () {
    double n, cost;
    scanf("%lf", &n);
    n <= 3 ? cost = 14 : cost = 13 + (n - 3) * 2.3 + 1;
    printf("%.1lf", cost);
    return 0;
}
