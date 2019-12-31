/*************************************************************************
	> File Name: 3.func.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 16时57分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

int funcA(int);
int funcB(int);

int funcB (int n) {
    printf("funcB : %d\n", n);
    if (!n) return 0;
    funcA(n - 1);
    return n;
}

int funcA (int n) {
    printf("funcA : %d\n", n);
    if (!n) return 0;
    funcB(n - 1);
    return n;
}
