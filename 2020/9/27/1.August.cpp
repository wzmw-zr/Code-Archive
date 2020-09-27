/*************************************************************************
	> File Name: 1.August.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月27日 星期日 09时13分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

#define PI 3.14159265358979323846

int t;
double a, b, ans;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf", &a, &b);
        ans = 4 * a * b + PI * a * a;
        printf("%.8lf\n", ans);
    }
    return 0;
}
