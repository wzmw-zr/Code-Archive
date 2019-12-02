/*************************************************************************
	> File Name: shape.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 01时33分57秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main () {
    char c;
    scanf("%c", &c);
    int scope = c - 'A';
    for (int i = 0; i <= scope; i++) {
        for (int j = 1;j <= i; j++) printf(" ");
        for (int j = i; j <= scope; j++) printf("%c", c - j);
        for (int j = scope; j >= i + 1; j--) printf("%c", c - j);
        printf("\n");
    }
    return 0;
}
