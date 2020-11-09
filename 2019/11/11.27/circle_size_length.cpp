/*************************************************************************
	> File Name: circle_size_length.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 01时34分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#define pi 3.14
using namespace std;

int main () {
    double r;
    scanf("%lf", &r);
    printf("%.2lf\n%.2lf", 2 * pi * r, pi * r * r);
    return 0;
}
