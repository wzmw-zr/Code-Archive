/*************************************************************************
	> File Name: 6.EP44.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 18时42分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


inline long pentagonal(long n) {
    return n * (3 * n - 1) / 2;
}

long binary_search(long (*func)(long), long n, long x) {
    long head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return mid;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    long n = 2, D = INT32_MAX, pk, pj;
    while (pentagonal(n) - pentagonal(n - 1) < D) {
        pk = pentagonal(n);
        for (long j = n - 1; j >= 1; j--) {
            pj = pentagonal(j);
            if (pk - pj >= D) break;
            long flag = 1;
            flag = binary_search(pentagonal, 2 * n, pk + pj);
            flag  = flag && binary_search(pentagonal, n, pk - pj);
            if (flag) {
                if (D > pk - pj) D = pk - pj;
            }
        }
        n++;
    }
    printf("%lld\n", D);
    return 0;
}
