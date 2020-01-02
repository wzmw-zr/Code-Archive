/*************************************************************************
	> File Name: 5.HOJ227.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月01日 星期三 11时48分52秒
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
#define MID 10000000000
using namespace std;

long mul(long x, long y, long p) {
    long a = x / MID, b = x % MID, c = y / MID, d = y % MID, res = 0;
    res = (a * c) % p;
    res = (((res * MID) % p) * MID) % p;
    res = (res + (((a * d) % p) * MID) % p) % p;
    res = (res + (((b * c) % p) * MID) % p) % p;
    res = (res + (b * d) % p) % p;
    return res;
}

int main() {
    long a, b, p;
    cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;
    return 0;
}
