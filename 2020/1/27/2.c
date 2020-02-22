/*************************************************************************
	> File Name: 2.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月27日 星期一 10时01分49秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

int main() {
    char cmd[10] = "ls";
    system(cmd);
    return 0;
}
