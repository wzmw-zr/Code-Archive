/*************************************************************************
	> File Name: 26.up.low.reverse.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 20时33分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 100
using namespace std;

char name[max_n + 5][100];

void solve(int i) {
    int len = strlen(name[i]);
    if (name[i][0] - 'a' >= 0) name[i][0] -= 32;
    for (int j = 1; j < len; j++) {
        if (name[i][j] - 'a' >= 0) continue;
        name[i][j] += 32;
    }
}


void sort_s(int n) {
    char x[100];
    for (int i = n; i >= 2; i--) {
        for (int j = 1; j <= i - 1; j++) {
            if (strcmp(name[j], name[j + 1]) <= 0) continue;
            strcpy(x, name[j]);
            strcpy(name[j], name[j + 1]);
            strcpy(name[j + 1], x);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", name[i]);
        solve(i);
    }
    sort_s(n);
    for (int i = 1; i <= n; i++) printf("%s\n", name[i]);
    return 0;
}
