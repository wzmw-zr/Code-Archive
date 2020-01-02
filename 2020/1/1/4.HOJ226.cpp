/*************************************************************************
	> File Name: 4.HOJ226.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月01日 星期三 11时30分01秒
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
#define MID 100000000
using namespace std;

long mul(long x, long y, long p) {
    long a = x / MID, b = x % MID, c = y / MID, d = y % MID, res = 0;
    res = a * c;
    res = (((res * MID) % p) * MID) % p;
    res = (res + (((a * d) % p) * MID) % p) % p;
    res = (res + (((b * c) % p) * MID) % p) % p;
    res = (res + (b * d) % p) % p;
    return res;
}

long quick_pow(long a, long b, long p) {
    long temp = a, res = 1;
    if (!b) return 1 % p;
    while (b) {
        if (b & 1) res = mul(res, temp, p);
        temp = mul(temp, temp, p);
        b >>= 1;
    }
    return res;
}

int main() {
    long a, b, p;
    cin >> a >> b >> p;
    cout << quick_pow(a, b, p);
    return 0;
}
