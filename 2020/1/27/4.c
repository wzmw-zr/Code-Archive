/*************************************************************************
	> File Name: 4.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月27日 星期一 10时36分39秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

int main() {
    char input[] = "A bird came down the walk";
    char* element[10] = {0};
    char *token = strtok(input, " ");
    int index = 0;
    while (token) {
        char* temp = (char *) malloc(sizeof(token) + 5);
        strcpy(temp, token);
        element[index++] = temp;
        token = strtok(NULL, " ");
    }
    for (int i = 0; element[i]; i++) {
        printf("%s\n", element[i]);
    }
    return 0;
}
