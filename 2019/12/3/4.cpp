/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 19时04分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) printf("FOOLISH");
    else if (n > 0 && n < 60) printf("FAIL");
    else if (n >= 60 && n < 75) printf("MEDIUM");
    else printf("GOOD");
    return 0;
}
