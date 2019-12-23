/*************************************************************************
	> File Name: 12.upstairs.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 16时32分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 50
using namespace std;

int num[max_n + 5] = {0};

void solve() {
    for (int i = 4; i <= max_n; i++) {
        num[i] = num[i - 2] + num[i - 3];
    }
}

int main() {
    num[2] = 1, num[3] = 1;
    int n;
    scanf("%d", &n);
    solve();
    printf("%d", num[n]);
    return 0;
}
