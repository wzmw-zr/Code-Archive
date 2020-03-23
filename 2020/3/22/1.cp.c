/*************************************************************************
	> File Name: 1.cp.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月22日 星期日 14时28分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#define MAX_N 100

#define BUFSIZE 512

int main(int argc, char **argv) {
    int fd_s, fd_t;
    ssize_t nread;
    char buf[BUFSIZE + 5];
    if (argc != 3) {
        printf("Usage: %s sourcefile destfile\n", argv[0]);
        exit(1);
    }  
    if ((fd_s = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }
    if ((fd_t = creat(argv[2], 0777)) == -1) {
        perror(argv[2]);
        exit(1);
    }
    while ((nread = read(fd_s, buf, sizeof(buf))) > 0) {
        if (write(fd_t, buf, nread) == -1) {
            perror("write");
            exit(1);
        }
    }
    close(fd_s);
    close(fd_t);
    return 0;
}
