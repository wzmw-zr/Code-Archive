/*************************************************************************
	> File Name: 3.client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月11日 星期六 14时30分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int GetSocket(char *host, int port) {
    int sockfd;
    struct sockaddr_in address;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(host);
    return sockfd;
}

void make_nonblock(int fd) {
    int flag = fcntl(fd, F_GETFD);
    flag |= O_NONBLOCK;
    if (fcntl(fd, F_SETFD, flag) == -1) {
        perror("fcntl");
        exit(1);
    }
}

int socket_connect_timeout(char *host, int port, long timeout) {
    int sockfd = GetSocket(host, port);
    make_nonblock(sockfd);
    return sockfd;
}

int main() {
    int sockfd = GetSocket("127.0.0.1", 8888);
    return 0;
}
