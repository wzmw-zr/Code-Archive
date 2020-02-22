/*************************************************************************
	> File Name: 6.file.io.up.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 14时49分23秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    printf("O_CREAT = %d\n", O_CREAT);
    int fd = open("new.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        printf("cannot open file\n");
        return -1;
    }
    int flag = fcntl(fd, F_GETFL);
    int accessible = flag & O_ACCMODE;
    if (accessible == O_RDONLY) printf("RDONLY\n");
    if (accessible == O_CREAT) printf("CREAT\n");
    flag |= O_RDWR;
    if (fcntl(fd, F_SETFL, flag) == -1) {
        printf("cannot set flag\n");
        return -1;
    }
    close(fd);
    return 0;
}
