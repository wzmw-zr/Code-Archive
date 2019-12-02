/*************************************************************************
	> File Name: cos.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 02时03分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main() {
    double x, y, arc, pi = acos(-1);
    int theta;
    scanf("%lf%lf%d", &x, &y, &theta);
    arc = theta * pi / 180;
    printf("%.6lf", sqrt(x * x + y * y - 2 * x * y * cos(arc)));
    return 0;
}
