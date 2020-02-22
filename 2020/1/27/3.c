/*************************************************************************
	> File Name: 3.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月27日 星期一 10时13分03秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

int main() {
    char cwd[80];
    getcwd(cwd, sizeof(cwd));
    int pid = fork();
    if (!pid) {
        strcat(cwd, "/1.out");
        execl(cwd, "1.out", NULL);
        exit(0);
    } else {
        int status;
        wait(&status);
    }
    return 0;
}
