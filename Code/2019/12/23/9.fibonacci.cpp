/*************************************************************************
	> File Name: 9.fibonacci.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 15时32分28秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


int func(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return func(n - 1) + func(n - 2); 
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
    return 0;
}
