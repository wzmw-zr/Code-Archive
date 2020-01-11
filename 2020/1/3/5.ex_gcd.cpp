/*************************************************************************
	> File Name: 5.ex_gcd.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月03日 星期五 22时37分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
using namespace std;

int ex_gcd(int a, int b, int *x, int *y) {
    int ret = b ? ex_gcd(b, a % b, x, y) : a;
    if (b == 0) {
        *x = 1, *y = 0;
        return ret;
    }
    int temp_1 = *x, temp_2 = *y;
    *x = temp_2, *y = temp_1 - (a / b) * temp_2;
    return ret;
}

int main() {
    int a, b, x, y;
    cin >> a >> b;
    int ret = ex_gcd(a, b, &x, &y);
    printf("a * %d + b * %d = %d\n", x, y, ret);
    return 0;
}
