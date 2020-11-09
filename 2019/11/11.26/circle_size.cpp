/*************************************************************************
	> File Name: circle_size.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 01时30分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#define pi 3.14
using namespace std;

int main () {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    printf("%.2lf", pi * r1 * r1 - pi * r2 * r2);
    return 0;
}
