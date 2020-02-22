/*************************************************************************
	> File Name: 1.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月29日 星期三 08时59分19秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

int main() {
    char dir[80];
    getcwd(dir, sizeof(dir));
    printf("%s\n", dir);
    printf("%d\n", strlen(dir));
    char up[80] = "/../";
    strcat(dir, up);
    //printf("%s\n", dir);
    char upper[10] = "./../";
    chdir(upper);
    char now[80];
    getcwd(now, sizeof(now));
    printf("%s\n", now);
    return 0;
}
