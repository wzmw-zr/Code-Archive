/*************************************************************************
	> File Name: 5.file.io.up.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 14时40分28秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int fd = open("new.txt", O_RDONLY | O_CREAT, S_IWUSR | S_IRUSR);
    if (fd == -1) {
        printf("cannot open File\n");
        return -1;
    }
    int flag = fcntl(fd, F_GETFL);
    if (flag == -1) {
        printf("cannot get flag !\n");
        return -1;
    }
    flag |= O_RDWR;
    if (fcntl(fd, F_SETFL, flag) == -1) {
        printf("cannot set flag\n");
        return -1;
    }
    close(fd);
    return 0;
}
