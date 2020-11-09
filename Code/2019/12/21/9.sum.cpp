/*************************************************************************
	> File Name: 9.sum.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 23时09分53秒
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


int if_sum(int *a, int left, int right, int i, int s) {
    if (left >= right) return 0;
    int mid = (left + right) >> 1;
    if (a[i] + a[mid] == s) return 1;
    else if (a[i] + a[mid] < s) {
        return if_sum(a, mid + 1, right, i, s);
    }else {
        return if_sum(a, left, mid - 1, i, s);
    }
}

int main() {
    int a[max_n + 5];
    int n, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &s);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (if_sum(a, 0, n - 1, i, s) == 1) {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}
