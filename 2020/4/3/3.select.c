/*************************************************************************
	> File Name: 3.select.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月03日 星期五 15时51分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define max(a, b) (a > b ? a : b)

fd_set rset, wset;
int maxfd;

int GetSocket() {
    int sockfd;
    struct sockaddr_in address;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(8888);
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (void *) &address, sizeof(address)) < 0) {
        perror("bind");
        exit(1);
    }
    if (listen(sockfd, 20) < 0) {
        perror("listen");
        exit(1);
    }
    struct linger val;
    val.l_onoff = 1;
    val.l_linger = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (void *) &val, sizeof(val)) < 0) {
        perror("setsockopt");
        exit(1);
    }
    return sockfd;
}
 
int main() {
    int sockfd = GetSocket(); 
    int ret;
    maxfd = max(maxfd, sockfd);
    FD_ZERO(&rset);
    FD_ZERO(&wset);
    FD_SET(sockfd, &rset);
    while (1) {
        ret = select(maxfd + 1, &rset, &wset, NULL, NULL); 
        if (ret < 0) {
            perror("select");
            exit(1);
        }
        if (FD_ISSET(sockfd, &rset)) {
            printf("listen fd get connect request!\n");
            int fd = accept(sockfd, NULL, NULL);
            maxfd = max(maxfd, fd);
            printf("new fd = %d\n", fd);
            close(fd);
        }
        for (int i = sockfd + 1; i <= maxfd; i++) {
            if (FD_ISSET(i, &rset)) printf("read from socket!\n");
            if (FD_ISSET(i, &wset)) printf("need to write to socket!\n");
        }
    }
    return 0;
}
