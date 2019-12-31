/*************************************************************************
	> File Name: 2.EP43.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 10时14分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 10000000000
using namespace std;

int digital(long x) {
    return floor(log10(x)) + 1;
}

int is_legal(long x) {
    int num[10] = {0};
    while (x) {
        if (num[x % 10]) return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int is_pandigital(long x) {
    if (digital(x) - 10) return 0;
    if (!is_legal(x)) return 0;
    return 1;
}

int is_val(long x) {
    int num[10] = {2, 3, 5, 7, 11, 13, 17};
    for (int i = 0; i <= 6; i++) {
        long p = pow(10, 6 - i), temp = (x / p) % 1000;
        if (temp % num[i]) return 0;
    }
    return 1;
}

int main() {
    long sum = 0;
    for (long i = 1000000000; i < max_n; i++) {
        if (!is_pandigital(i)) continue;
        if (!is_val(i)) continue;
        sum += i;
        printf("sum = %lld\n", sum);
    }
    printf("%lld\n", sum);
    return 0;
}
