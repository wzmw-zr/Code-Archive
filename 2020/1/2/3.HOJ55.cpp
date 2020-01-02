/*************************************************************************
	> File Name: 3.HOJ55.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月02日 星期四 16时33分02秒
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

int is_val(int n) {
    int res = n + 23 + (int)floor(n / 4) - (int)floor(n / 100) + (int)floor(n / 400);
    res %= 7;
    return 5 == res;
}

int main() {
    int y1, m1, d1, y2, m2, d2, sum = 0;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    for (int i = y1 ; i <= y2; i++) sum += is_val(i);
    if (m1 > 6 || m1 == 6 && d1 > 6) sum--;
    if (m2 < 6 || m2 == 6 && d2 < 6) sum--;
    cout << sum <<endl;
}
