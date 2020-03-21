/*************************************************************************
	> File Name: 6.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月20日 星期五 19时05分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char **argv) {
    char *buffer = (char *) calloc(sizeof(char), 100);
    char filename[100] = "input";
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    read(fd, buffer, 50);
    printf("%s\n", buffer);
    close(fd);
    return 0;
}
