/*************************************************************************
	> File Name: 8.peach.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 15时26分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


int func(int num, int n) {
    if (n == 1) return num;
    return func(2 * num + 2, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(1, n));
    return 0;
}
