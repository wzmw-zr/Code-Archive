/*************************************************************************
	> File Name: 9.HOJ438.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 15时24分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

int main() {
    int n;
    double cost;
    cin >> n;
    if (n < 240) cost = n * 0.4783;
    else if (n <= 400) cost = 240 * 0.4783 + (n - 240) * 0.5283;
    else cost = 240 * 0.4783 + 160 * 0.5283 + (n - 400) * 0.7783;
    printf("%.1lf", cost);
    return 0;
}
