/*************************************************************************
	> File Name: 1.longest.number.chain.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 09时18分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define MAX_N 1000000
using namespace std;

int number[MAX_N + 5] = {0};

long get_number(long n) {
    long count = 0;
    while (n != 1) {
        if (n & 1) {
         n = 3 * n + 1;
        }
        else {
            n = n / 2;
        }
        count++;
    }
    return count;
}

int main() {
    long count = 0, x;
    for (long i = 1; i <= MAX_N; i++) {
        x = get_number(i);
        count < x ? count = x : count = count;
    }
    printf("%lld", count);
    return 0;
}
