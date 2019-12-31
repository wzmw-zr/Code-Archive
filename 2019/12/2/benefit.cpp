/*************************************************************************
	> File Name: benefit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 01时57分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main () {
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    printf("%.6lf", x * pow(1.06, n));
    return 0;
}
