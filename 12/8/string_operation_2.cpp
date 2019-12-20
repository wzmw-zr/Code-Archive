/*************************************************************************
	> File Name: string_operation_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 13时37分48秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;

int main () {
    char a[10000], b[10000], c[10000];
    int n;
    scanf("%s%d%s", a, &n, b);
    int len_a = strlen(a);
    int len_b = strlen(b);
    printf("%d\n", len_a);
    for (int i = 0; i < len_a;i++) {
        if (a[i] == 'a') {
            printf("%d\n", ++i);
            break;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        c[i] = a[i];
    }
    strcat(c, b);
    for (int i = n - 1; i < len_a; i++) {
        c[i + len_b] = a[i];
    }
    printf("%s", c);
    return 0;
}
