/*************************************************************************
	> File Name: mod_equation.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 09时14分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


int ex_gcd (int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1;
        *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    *x = yy;
    *y = xx - a / b * yy;
    return ret;
}


int main () {
    int a, b, x, y;
    scanf("%d%d", &a, &b);
    int ret = ex_gcd(a, b, &x, &y);
    for (int i = 0; ; i++) {
        if (x > 0) break;
        x += b / ret;
    }
    printf("%d", x);
    return 0;
}
