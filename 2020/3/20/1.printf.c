/*************************************************************************
	> File Name: 1.printf.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月20日 星期五 07时54分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int max_l;

int main(int argc, char **argv) {
    int t_argc = argc, len;
    char **t_argv = argv;
    while (--t_argc) {
        len = strlen(*(++t_argv));
        max_l = max_l > len ? max_l : len;
    }
    while (--argc) {
        printf("%-*s\n", len, *(++argv));
    }
    return 0;
}
