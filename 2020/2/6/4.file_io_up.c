/*************************************************************************
	> File Name: 4.file_io_up.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 14时32分12秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int fd = open("new.txt", O_RDWR, S_IWUSR | S_IRUSR);
    if (fd == -1) {
        printf("error\n");
        return 1;
    }
    int flag = fcntl(fd, F_GETFL);
    printf("flag = %d\n", flag);
    if (flag & O_SYNC) printf("SYNC\n");
    int accessible = flag & O_ACCMODE;
    if (accessible == O_RDWR) printf("O_RDWR\n");
    close(fd);
    return 0;
}
