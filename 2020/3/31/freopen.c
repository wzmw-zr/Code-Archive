/*************************************************************************
	> File Name: freopen.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月31日 星期二 19时52分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp = freopen("output.txt", "w+", stdout);
    while (1) {
        char line[100];
        scanf("%s", line);
        printf("%s\n", line);
        fflush(fp);
    }
    return 0;
}
