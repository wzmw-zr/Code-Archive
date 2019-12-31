/*************************************************************************
	> File Name: quickpow.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月31日 星期二 16时49分18秒
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
using namespace std;

long quickpows(long a, long b) {
    long temp = a, ans = 1;
    while (b) {
        if (b & 1) ans *= temp;
        temp = temp * temp;
        b >>= 1;
    }
    return ans;
}

int main() {
    long a, b;
    cin >> a >> b;
    cout << quickpows(a, b) << endl;
    return 0;
}
