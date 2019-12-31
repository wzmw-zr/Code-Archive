/*************************************************************************
	> File Name: 21.pow.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 18时44分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

long pow(int n) {
    long ret = 1;
    while (n--) ret *= 2;
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", pow(n));
    return 0;
}
