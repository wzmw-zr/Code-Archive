/*************************************************************************
	> File Name: 20.solution.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 18时31分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define EPSILON 10E-6
using namespace std;


double solve(int p, int q) {
    double left = -20.0, right = 20.0, mid;
    while (right - left >= EPSILON) {
        mid = (left + right) / 2;
        if ((p * 1.0) * mid + q * 1.0 == 0) return mid;
        else if ((p * 1.0) * mid + q * 1.0 > 0) {
            if (p > 0) right = mid;
            else left = mid;
        }
        else {
            if (p > 0) left = mid;
            else right = mid;
        }
    }
    return mid;
}

int main() {
    int p, q;
    scanf("%d%d", &p, &q);
    printf("%.4lf", solve(p, q));
    return 0;
}
