/*************************************************************************
	> File Name: 24.char.shape.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 20时07分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 26
using namespace std;

char s[max_n + 5] = {0};

void change() {
    int len = strlen(s);
    char tmp[max_n + 5] = {0};
    strcpy(tmp, s);
    memset(s, 0, sizeof(s));
    s[0] = tmp[len - 2], s[1] = tmp[len - 1];
    for (int i = 0; i <= len - 3; i++) {
        s[i + 2] = tmp[i];
    }
}

void solve() {
    int len = strlen(s);
    printf("%s\n", s);
    for (int i = 1; i < len; i++) {
        change();
        printf("%s\n", s);
    }
}

int main() {
    scanf("%s", s);
    solve();
    return 0;
}
