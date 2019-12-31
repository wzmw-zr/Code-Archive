/*************************************************************************
	> File Name: 3.swap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 16时43分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<inttypes.h>
#include<stdarg.h>
#include<math.h>
using namespace std;


void swap_1 (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}


void swap_2 (int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}


void swap_3 (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return ;
}
int main () {
    int a, b;
    scanf("%d%d", &a, &b);
    swap_2(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
