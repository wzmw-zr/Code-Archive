/*************************************************************************
	> File Name: 3.EP22.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 10时20分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include "3.EP22.h"
using namespace std;

int cmp(string a, string b) {
    if (a.compare(b) <= 0) return 1;
    return 0;
}

long val(string a) {
    long ret = 0;
    for (long i = 0; i < a.length(); i++) {
        ret += a[i] - 'A' + 1;
    }
    return ret;
}

int main() {
    long len, num = 0, i = 0, sum = 0;
    while ((len = name_list[i].length()) > 0) i++, num++;
    sort(name_list, name_list + num, cmp);
    for (long i = 0; i < num; i++) {
        sum += (i + 1) * val(name_list[i]);
    }
    cout << sum << endl;
    return 0;
}
