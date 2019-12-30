/*************************************************************************
	> File Name: 7.EP42.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月29日 星期日 15时25分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 2500
#include "input.txt"
using namespace std;

int triangle(int n) {
    return n * (n + 1) / 2;
}

bool binary_search(int (*func)(int), int l, int r, int num) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (func(mid) == num) return true;
    if (func(mid) < num) l = mid + 1;
    else r = mid - 1;
    return binary_search(func, l, r, num);
}

bool is_val(char *str) {
    int sum = 0;
    for (int i = 0; str[i]; i++) {
        sum += str[i] - 'A' + 1;
    }
    return binary_search(triangle, 1, sum, sum);
}


int main() {
    int n = sizeof(str) / 100, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (is_val(str[i])) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
