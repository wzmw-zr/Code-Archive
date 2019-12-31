/*************************************************************************
	> File Name: gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 18时35分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


int gcd(int a, int b) {
    return (a % b ? gcd(b, a % b) : b);
    //return (b ? gcd(b, a % b) : a);
}



int main () {
    int a, b;
   while(~scanf("%d%d", &a, &b)){
    printf("%d", gcd(a, b));
    return 0;
    }
}
