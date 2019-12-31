/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 18时30分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main () {
    int a, b;
    scanf("%d%d", &a, &b);
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("%d %d", a, b);
    return 0;
}
