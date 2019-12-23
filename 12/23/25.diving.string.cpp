/*************************************************************************
	> File Name: 25.diving.string.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 20时21分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 20
#define max_l 10000000
using namespace std;

char s[max_n + 5][max_l + 5] = {0};

void init() {
    char axis = 'A';
    s[1][0] = 'A';
    for (int i = 2; i <= max_n; i++) {
        axis++;
        int len = strlen(s[i - 1]);
        strcpy(s[i], s[i - 1]);
        s[i][len] = axis;
        strcat(s[i], s[i - 1]);
    }
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    printf("%s", s[n]);
    return 0;
}
