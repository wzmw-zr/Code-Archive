/*************************************************************************
	> File Name: 14.EP26.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 20时27分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000
using namespace std;

int r_len[max_n + 5] = {0};

int get_len(int d) {
    int r = 1, t = 1;
    r_len[r] = 1;
    while (r) {
        r = (r * 10) % d;
        t += 1;
        if (r_len[r]) return t - r_len[r];
        r_len[r] = t;
    }
    return 0;
}

int main() {
    int d = 0, len = -1;
    for (int i = 2; i < max_n; i++) {
        memset(r_len, 0, sizeof(r_len));
        int temp = get_len(i);
        if (len < temp) len = temp, d = i;
    }
    cout << d << " " << len << endl;
    return 0;
}

