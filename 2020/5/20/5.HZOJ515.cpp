/*************************************************************************
	> File Name: 5.HZOJ515.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 19时28分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

int a, b, l;
int r_a, r_b;
double d = 0x3f3f3f3f * 1.0;

int main() {
    cin >> a >> b >> l;
    double a_b = (1.0 * a) / (1.0 * b);
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            double temp = (1.0 * i) / (1.0 * j);
            if (temp >= a_b && temp - a_b < d) {
                r_a = i, r_b = j;
                d = temp - a_b;
            }
        }
    }
    cout << r_a << " " << r_b << endl;
    return 0;
}
