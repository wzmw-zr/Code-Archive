/*************************************************************************
	> File Name: 27.password.translate.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 20时51分33秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 26
#define max_l 30
using namespace std;

char c[max_n + 5];
int num[max_n + 5];
char password[max_l + 5];


int get_val(char x, int n) {
    for (int i = 1; i <= n; i++) {
        if (x != c[i]) continue;
        return num[i];
    }
    return 0;
}

void solve(int n) {
    int ret = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] - 'a' >= 0) continue;
        ret += get_val(password[i], n);
    }
    printf("%d", ret);
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%c\n", &c[i]);
        scanf("%d\n", &num[i]);
    }
    scanf("%s\n", password);
    solve(n);
    return 0;
}
