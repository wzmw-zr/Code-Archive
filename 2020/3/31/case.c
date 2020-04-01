/*************************************************************************
	> File Name: case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月31日 星期二 19时15分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *parse_purpose(char *line) {
    int len = strlen(line), i, j;
    for (i = 0; line[i] && line[i] != '@'; i++);
    if (i == len) return NULL;
    for (j = i + 1; line[j] && line[j] != ':'; j++);
    char *name = (char *) calloc(sizeof(char), 100);
    strncpy(name, line + i + 1, j - i - 1);
    return name;
}

int main() {
    char line[100];
    scanf("%[^\n]s", line);
    printf("%s\n", parse_purpose(line)); 
    return 0;
}
