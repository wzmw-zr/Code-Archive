/*************************************************************************
	> File Name: 28.forbid.smoke.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 21时08分57秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000
#define max_l 100
using namespace std;

char s[max_n + 5][max_l + 5] = {0};
char re[max_l + 5] = "No_smoking";
char res[max_l + 5] = "Ban_smoking";

void change(int i, int j) {
    char tmp[max_l + 5] = {0};
    int len = strlen(s[i]);
    for (int m = 0, k = j + 11; k < strlen(s[i]); m++, k++) tmp[m] = s[i][k];
    for (int m = 0, k = j; m < 10; m++, k++) s[i][k] = re[m];
    for (int k = j + 10; k < len; k++) s[i][k] = 0;
    if (strlen(tmp) > 0) strcat(s[i], tmp);
}

void handle(int i) {
    for (int j = 0; j < strlen(s[i]); j++) {
        int flag = 0;
        for (int k = 0; k < 11; k++) {
            if (res[k] == s[i][j + k]) continue;
            flag = 1;
            break;
        }
        if (flag) continue;
        change(i, j);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i]);
        handle(i);
    }
    for (int i = 1; i <= n; i++) printf("%s\n", s[i]);
    return 0;
}
