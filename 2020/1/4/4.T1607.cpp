/*************************************************************************
	> File Name: 4.T1607.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月04日 星期六 09时07分25秒
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

void swap(long *a, long *b) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

long gcd(long a, long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    long a, b, c;
    cin >> a >> b >> c;
    swap(&a, &b);
    swap(&b, &c);
    swap(&a, &c);
    long x = 2 * b * c, y = b * b + c * c - a * a;
    long res = gcd(x, y);
    x /= res, y /= res;
    long z = (int) sqrt(x * x - y * y);
    res = gcd(x, z);
    cout << z / res << "/" << x / res << endl;
    return 0;
}
