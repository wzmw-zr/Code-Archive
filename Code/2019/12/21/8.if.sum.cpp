/*************************************************************************
	> File Name: 8.if.sum.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 23时01分15秒
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


void if_sum(int *a, int left, int right, int k, int s) {
    if (left > right) {
        printf("No");
        return;
    }
    int mid = (left + right) >> 1;
    if (a[mid] + k == s) {
        printf("Yes");
        return;
    } else if (a[mid] + k < s) {
        if_sum(a, mid + 1, right, k, s);
    } else {
        if_sum(a, left, mid - 1, k, s);
    }
}


int main() {
    int a[max_n + 5];
    int n, k, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d%d", &k, &s);
    if_sum(a, 0, n - 1, k, s);
    return 0;
}
