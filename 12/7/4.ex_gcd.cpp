/*************************************************************************
	> File Name: 4.ex_gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 20时09分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


int ex_gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
   // int xx, yy, ret = ex_gcd(b, a % b, x, y);
   // xx = *y;
   // yy = *x - a / b * xx;
   // *x = xx;
   // *y = yy;
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    *x = yy;
    *y = xx - a / b * yy;
    return ret;
}


int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        //printf("%d %d\n", x, y);
        printf(" %d * %d + %d * %d = %d\n", a , x, b, y, a * x + b * y);
    }
    return 0;
}
