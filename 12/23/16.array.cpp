/*************************************************************************
	> File Name: 16.array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 17时03分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 30
using namespace std;

long numerator[max_n + 5] = {0};
long  denominator[max_n + 5] = {0};

void init() {
    numerator[1] = 4, numerator[2] = 7;
    denominator[1] = 7, denominator[2] = 11;
    for (int i = 3; i <= max_n; i++) {
        numerator[i] = numerator[i - 1] + numerator[i - 2];
        denominator[i] = denominator[i - 1] + denominator[i - 2];
    }
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += numerator[i] * 1.0 / denominator[i] * 1.0;
    }
    printf("%d/%d\n", numerator[n], denominator[n]);
    printf("%.2lf", sum);
    return 0;
}
