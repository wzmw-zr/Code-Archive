/*************************************************************************
	> File Name: picture.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月02日 星期一 01时20分11秒
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
    int m = 2 * n + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i; j++) printf(" ");
        printf("%d", n - i);
        for (int j = 1; j <= m - 2 * i - 2; j++) printf(" ");
        printf("%d\n", n - i);
    }
    for (int i = 1; i <= n; i++) printf(" ");
    printf("0\n");
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) printf(" ");
        printf("%d", n - i);
        for (int j = 1; j <= m - 2 * i - 2; j++) printf(" ");
        printf("%d\n", n - i);
    }
    return 0;
}
