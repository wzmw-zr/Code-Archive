/*************************************************************************
	> File Name: 1.complete.binary.tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月16日 星期日 00时08分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 1000

void output(char *str, int ind) {
    if (!str[ind]) return ;
    printf("%c", str[ind]);
    if (str[2 * ind]) {
        printf("(");
        output(str, 2 * ind);
        if (!str[2 * ind + 1]) printf(")");
    }
    if (str[2 * ind + 1]) {
        if (!str[2 * ind]) printf("(");
        printf(",");
        output(str, 2 * ind + 1);
        printf(")");
    }
    return ;
}

int main() {
    char str[max_n + 5] = {0}, tmp[max_n + 5];
    scanf("%[^$]s", tmp);
    for (int i = 0; tmp[i]; i += 2) str[i / 2 + 1] = tmp[i]; 
    output(str, 1);
    return 0;
}
