/*************************************************************************
	> File Name: 2.file_io.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 10时48分56秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int fd = open("case.txt", O_RDWR, S_IRUSR | S_IWUSR);
    printf("fd = %d\n", fd);
    char *tmp = (char *) calloc(100, sizeof(char));
    int end = lseek(fd, 0, SEEK_END);
    printf("len = %d\n", end);
    lseek(fd, 0, SEEK_SET);
    printf("read(fd, tmp, len) = %d\n", read(fd, tmp, end));
    close(fd);
    return 0;
}
