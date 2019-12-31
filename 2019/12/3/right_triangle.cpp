/*************************************************************************
	> File Name: right_triangle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 18时01分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main () {
    long c;
    long count = 0;
    scanf("%ld", &c);
    for (long i = 1; i < c; i++) {
        long b = (long) sqrt(c * c - i * i);
        if (b * b + i * i == c * c) count++;
    }
    printf("%d", count / 2);
    return 0;
}
