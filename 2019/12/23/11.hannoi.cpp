/*************************************************************************
	> File Name: 11.hannoi.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 15时47分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

long num(long n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return 2 * num(n - 1) + 1;
}

long power(long n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return 2 * power(n - 1) + n;

}

int main() {
    long n;
    scanf("%lld", &n);
    printf("%lld %lld", num(n), power(n));
    return 0;
}
