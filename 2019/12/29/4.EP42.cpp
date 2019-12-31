/*************************************************************************
	> File Name: 4.EP42.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 11时19分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include "4.EP42.h"
#define max_n 2500
using namespace std;

int is_triangle(int n) {
    int x = (int) sqrt(2 * n);
    if ((x * (x + 1)) >> 1 == n) return 1;
    return 0;
}

int main() {
    int count = 0;
    for (int i = 0; i <= max_n; i++) {
        int len = a[i].length();
        if (!len) break;
        int num = 0;
        for (int j = 0; j < len; j++) num += a[i][j] - 'A' + 1;
        if (is_triangle(num)) count++;
    }
    cout << count << endl;
    return 0;
}
