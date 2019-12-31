/*************************************************************************
	> File Name: 9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 20时46分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    int digits = 0;
    do {n /= 10;
        digits++;
    } while (n);
    printf("%d", digits);
    return 0;
}
