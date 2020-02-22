/*************************************************************************
	> File Name: 2.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月29日 星期三 09时44分07秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

void print(const char *tmp) {
    printf("%s\n", tmp);
    printf("%d\n", strlen(tmp));
}

int main() {
    char temp[80];
    getcwd(temp, sizeof(temp));
    print(temp);
    return 0;
}
