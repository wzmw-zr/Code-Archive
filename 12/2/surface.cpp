/*************************************************************************
	> File Name: surface.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 01时48分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main () {
    //const double pi = acos(-1);
    double pi = 3.14;
    double r, h;
    scanf("%lf%lf", &r, &h);
    printf("%.2lf", h * (pi * r + 2 * r + 2 * r * sqrt(2)) + pi * r * r + 4 * r * r);
    return 0;
}
