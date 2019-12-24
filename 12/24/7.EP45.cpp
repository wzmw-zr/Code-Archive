/*************************************************************************
	> File Name: 7.EP45.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 19时46分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;
typedef long int1;

int1 triangle(int1 n) {
    return n * (n + 1) / 2;
}

int1 pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 hexagonal(int1 n) {
    return n * (2 * n - 1);
}

int1 binary_search(int1 (*num)(int1), int1 n, int1 number) {
    int1 head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == number) return mid;
        if (num(mid) < number) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    int1 n = 144;
    while (binary_search(pentagonal, 2 * n, hexagonal(n)) ==  -1) n++;
    cout << hexagonal(n) << endl;
    return 0;
}
