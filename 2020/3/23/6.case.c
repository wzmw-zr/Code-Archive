/*************************************************************************
	> File Name: 6.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月23日 星期一 21时08分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int GetFile(char *filepath) {
    int fd;
    printf("filepath = %s\n", filepath);
    if ((fd = open(filepath, O_RDWR)) == -1) {
        perror(filepath);
        exit(1);
    }
    return fd;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s filename\n", argv[0]);
        exit(1);
    }
    int fd = GetFile(argv[1]);
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }
    return 0;
}
