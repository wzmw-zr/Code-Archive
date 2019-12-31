/*************************************************************************
	> File Name: print_picture.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 01时07分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main () {
    int n;
    char first = 'A';
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) printf(" ");
        for (int j = i; j <=n; j++) printf("%c", first + j - 1);
        for (int j = n - 1; j >= i; j--) printf("%c", first + j - 1);
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i - 1; j++) printf(" ");
        for (int j = i; j <= n; j++) printf("%c", first + j - 1);
        for (int j = n - 1; j >= i; j--) printf("%c", first + j - 1);
        printf("\n");
    }
    return 0;
}
