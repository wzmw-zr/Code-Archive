/*************************************************************************
	> File Name: 6.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月07日 星期二 19时17分29秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#define epsilon 1e-7
using namespace std;

double n; 

double get_res(double left, double right) {
    if (right - left < epsilon) return left;
    double mid = (left + right) / 2.0;
    if (mid * mid == n) return mid;
    if (mid * mid < n) left = mid;
    else right = mid;
    return get_res(left, right);
}

double my_sqrt_1(double right) {
    double l = 0, r = right;
    while (r - l > epsilon) {
        double mid = (l + r) / 2.0;
        if (mid * mid <= n) l = mid;
        else r = mid;
    }
    return l;
}

double my_sqrt_2(double right) {
    double l = 0, r = right;
    for (int i = 0; i < 10000; i++) {
        double mid = (l + r) / 2.0;
        if (mid * mid <= n) l = mid;
        else r = mid;
    }
    return l;
}

double f(double x, double n) {
    return x * x - n;
}

double f_prime(double x) {
    return 2 * x;
}

double newtown(double n) {
    double x = 1.0;
    int cnt = 0;
    while (fabs(f(x, n)) > epsilon) {
        x = x - f(x, n) / f_prime(x);
        cnt += 1;
    }
    printf("run %d times\n", cnt);
    return x;
}

int main() {
    cin >> n;
    int right = (n > 1) ? n : 1;
    cout << newtown(right) << endl;
    return 0;
}
