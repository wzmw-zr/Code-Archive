/*************************************************************************
	> File Name: 1.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月27日 星期一 09时34分24秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

int main() {
    char cwd[80];
    getcwd(cwd, sizeof(cwd));
    printf("%s$\n", cwd);
    return 0;
}
