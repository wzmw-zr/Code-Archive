/*************************************************************************
	> File Name: benefit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 19时07分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    double m;
    int n;
    double result = 0;
    scanf("%lf%d", &m, &n);
    for (int i = 1; i <= n ; i++) {
        result += m;
        result *= 1.00417;
    }
    printf("$%.2lf", result); 
    return 0;
}
