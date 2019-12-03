/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 19时27分35秒
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
    switch (n) {
        case 1:
            printf("one ");
        case 2:
            printf("two ");
        case 3:
            printf("three");
            break;
        default:
            printf("error");
            break;
    }
    return 0;
}
