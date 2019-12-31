/*************************************************************************
	> File Name: string_operation.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 11时28分56秒
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
    scanf("%s", a);
    scanf("%d", &n);
    scanf("%s", b);
    strlen(a) > 100 && printf("%d\n", 100);
    strlen(a) <= 100 && printf("%d\n", strlen(a));
    for (int i = 0; i < n - 1; i++) c[i] = a[i];
    strcat(c, b);
    int length = strlen(c);
    for (int i = n - 1; i < strlen(a); i++) c[length++] = a[i];
    printf("%s\n", c);
    for (int i = strlen(c) - 1, j = 1; i >= 0; i--, j++) {
        if (c[i] == 'x') {
            printf("%d", j);
            break;
        }
    }
    return 0;
}
