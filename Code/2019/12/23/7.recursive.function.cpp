/*************************************************************************
	> File Name: 7.recursive.function.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 15时22分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


int func(int x) {
    if (x <= 0) return 0;
    else if (x == 1) return 1;
    else if (x % 2) return 3 * func((x + 1) / 2) - 1;
    else return 3 * func(x / 2) - 1;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", func(x));
    return 0;
}
