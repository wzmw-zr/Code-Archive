/*************************************************************************
	> File Name: regular_name.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 13时47分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


void swap(char a[100], char b[100]) {
    char c[100];
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
}

void sort_string (int n,  char name[][100]) {
    for (int k = n - 1; k >= 0; k--) {
        for (int i = 0; i <= k; i++) {
            (strcmp(name[i], name[i + 1]) > 0) && swap(name[i], name[i + 1]); 
         }
    }
}

int main () {
    int n;
    scanf("%d", &n);
    char name[n][100];
    for (int i = 0; i < n; i++) {
        scanf("%s", name[i]);
        if (name[i][0] >= 'a' && name[i][0] <= 'z') name[i][0] -= 32;
        int length = strlen(name[i]);
        for (int j = 1; j < length; j++) {
            (name[i][j] >= 'A' && name[i][j] <= 'Z') && (name[i][j] += 32);
        }
    }
    sort_string(n, name[n][100]);
    for (int i = 0; i < n; i++) {
        printf("%s\n", name[i]);
    }
    return 0;
}
