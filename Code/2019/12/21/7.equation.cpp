/*************************************************************************
	> File Name: 7.equation.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 22时35分29秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000000000
using namespace std;


double func(double x, double a) {
    return x * exp(x) - a;
}

double get_val(double a, double left, double right) {
    double mid = (left + right) / 2;
    if (right - left < 0.00001) return mid;
    double ret = func(mid, a);
    if (ret == 0) return mid;
    else if (ret < 0) return get_val(a, mid, right);
    else return get_val(a, left, mid);
}


int main() {
    double a;
    scanf("%lf", &a);
    printf("%.4lf", get_val(a, 0 * 1.0, a * 1.0));
    return 0;
}
