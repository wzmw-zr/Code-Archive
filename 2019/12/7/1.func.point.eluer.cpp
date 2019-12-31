/*************************************************************************
	> File Name: 1.func.point.eluer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 15时32分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<inttypes.h>
using namespace std;

typedef int64_t int1;

int1 triangle(int1 n) {
    return n * (n + 1) / 2;
}

int1 pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 hexagonal(int1 n) {
    return n * (2 * n - 1);
}

int1 binary_search(int1 (*func)(int1), int1 x) {
    int1 head = 1, tail = x, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return mid;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    int n = 144; 
    for(;; n++){
        if (binary_search(pentagonal, hexagonal(n)) == -1) continue;
        printf("%" PRId64 "\n", hexagonal(n));
        break;
    }
    return 0;
}
