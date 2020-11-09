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

int call_num(int left, int right, int x) {
    while (left < right) {
        //printf("left = %d, right = %d", left, right);
        int mid  = (left + right + 1) >> 1;
        //printf("mid = %d\n", mid);
        if (a[mid] <= x) left = mid;
        else right = mid - 1;
    }
    return a[left];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &q[i]);
    for (int i = 1; i <= m; i++) {
        i == m && printf("%d", call_num(1, n, q[i]));
        i != m && printf("%d ", call_num(1, n, q[i]));
    }
    return 0;
}
