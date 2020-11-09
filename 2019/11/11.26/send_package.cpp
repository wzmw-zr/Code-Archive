/*************************************************************************
	> File Name: send_package.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 01时16分37秒
 ************************************************************************/

#include <stdio.h>

int main () {
    double x, cost;
    scanf("%lf", &x);
    x <= 15 ? cost = 6 * x : cost = 15 * 6 + (x - 15) * 9;
    printf("%.2lf", cost);
    return 0;
}
