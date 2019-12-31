/*************************************************************************
	> File Name: 10.spring.board.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 15时39分56秒
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

int a[max_n + 5] = {0};

int solve(int s, int n) {
    if (s > n) return 0;
    return 1 + solve(s + a[s], n);
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", solve(1, n));
    return 0;
}
