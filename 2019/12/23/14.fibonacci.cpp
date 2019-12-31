/*************************************************************************
	> File Name: 14.fibonacci.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 16时44分44秒
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

int num[max_n + 5] = {0};

void init() {
    num[1] = 1, num[2] = 1;
    int p = pow(10, 9) + 7;
    for (int i = 3; i <= max_n; i++) {
        num[i] += num[i - 1] + num[i - 2];
        num[i] %= p;
    }
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    printf("%d", num[n]);
    return 0;
}
