/*************************************************************************
	> File Name: taxi_cost.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 01时37分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    double n;
    scanf("%lf", &n);
    if (n <= 3) printf("14");
    else {
        double cost = 14.0 + 2.3 * (n - 3);
        printf("%.1lf", cost);
    }
    return 0;
}
