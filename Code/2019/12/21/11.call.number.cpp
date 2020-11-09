/*************************************************************************
	> File Name: 10.call.number.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 23时38分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 100000
using namespace std;

int a[max_n + 5], q[max_n + 5];

int call_num(int n, int x) {
    for (int i = 0; i < n - 1; i++) {
        if (i == 0 && a[i] >= x) return a[0];
        if (a[i] <= x && a[i + 1] > x) return a[i];
    }
    if (a[n - 1] <= x) return a[n - 1];
    return a[n - 2];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &q[i]);
    for (int i = 0; i < m; i++) {
        i == (m - 1) && printf("%d", call_num(n, q[i]));
        i != (m - 1) && printf("%d ", call_num(n, q[i]));
    }
    return 0;
}
