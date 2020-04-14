/*************************************************************************
	> File Name: 1.mmap.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月14日 星期二 17时48分55秒
 ************************************************************************/

#include<head.h>

int main() {
    int fd;
    if ((fd = open("./1.mmap.c", O_RDWR | O_CREAT, 0666)) < 0) {
        perror("open");
        exit(1);
    }
    int len = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    printf("%d\n", len);
    close(fd);
    return 0;
}
