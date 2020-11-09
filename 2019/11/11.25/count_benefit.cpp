/*************************************************************************
	> File Name: count_benefit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 00时20分38秒
 ************************************************************************/

#include<stdio.h>

int main() {
    double n, result;
    scanf("%lf", &n);
    result = n;
    for (int i = 0; i < 6; i++) {
        result *= 1.00417;
        if (i < 5) result += n;
    }
    printf("$%.2lf", result);
    return 0;
}
