/*************************************************************************
	> File Name: 7.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 19时27分28秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int a;

double bs(double l, double r) {
    while (1) {
        double mid = (l + r) / 2;
        if (abs(mid * exp(mid) - a) < 0.00001) return mid;
        if (mid * exp(mid) > a) r = mid;
        else l = mid;
    }
    return 0.0;
}


int main() {
    cin >> a;
    printf("%.4lf\n", bs(0.0, a * 1.0));
    return 0;
}
