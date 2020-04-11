/*************************************************************************
	> File Name: 1.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月10日 星期五 09时54分37秒
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
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
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
    if (setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &val, sizeof(val)) < 0) {
        perror("setsockopt");
        exit(1);
    }
    return sockfd;
}

void socket_connect_timeout(int sockfd, int max_fd, fd_set *allfds) { 
    for (int i = sockfd + 1; i <= max_fd; i++) {
        if (FD_ISSET(i, allfds)) {
            char msg[1024] = "long time no opeation! connection closed!";
            send(i, msg, strlen(msg), 0);
            FD_CLR(i, allfds);
            close(i);
        } 
    }
}

int main() {
    int sockfd = GetSocket(); 
    fd_set readfds, allfds;
    struct timeval timeout = {10, 0};
    int max_fd = sockfd;
    FD_ZERO(&readfds);
    FD_ZERO(&allfds);
    FD_SET(sockfd, &allfds);
    FD_SET(sockfd, &readfds);
    int num = 0;
    while (1) {
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        readfds = allfds;
        if ((num = select(max_fd + 1, &readfds, NULL, NULL, &timeout)) < 0) {
            perror("select");
            exit(1);
        } 
        printf("second = %d\n", timeout.tv_sec);
        printf("num = %d\n", num);
        if (timeout.tv_sec == 0)  {
            printf("timeout!\n");
            socket_connect_timeout(sockfd, max_fd, &allfds); 
            max_fd = sockfd;
            continue;
        }
        int fd;
        if (FD_ISSET(sockfd, &readfds)) {
            if ((fd = accept(sockfd, NULL, NULL)) < 0) {
                perror("accept");
                continue;
            }
            FD_SET(fd, &allfds);
            num--;
        }
        for (int i = sockfd + 1; i <= max_fd; i++) {
            if (!FD_ISSET(i, &readfds)) continue;
            char data[1024];
            int ret = 0;
            if ((ret = recv(i, data, sizeof(data), 0)) < 0) {
                perror("recv");
                FD_CLR(i, &allfds);
                close(i);
                continue;
            }
            if (ret == 0) {
                printf("peer close connection!\n");
                FD_CLR(i, &allfds);
                close(i);
                continue;
            }
            printf("%s", data);
        }
        max_fd = max_fd > fd ? max_fd : fd;
    }
    return 0;
}
