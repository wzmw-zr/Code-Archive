/*************************************************************************
	> File Name: 1.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月12日 星期日 14时23分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int GetSocket(int port) {
    int sockfd;
    struct sockaddr_in address;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    struct linger val;
    val.l_onoff = 1;
    val.l_linger = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &val, sizeof(val)) < 0) {
        perror("setsockopt");
        exit(1);
    }
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind");
        exit(1);
    }
    if (listen(sockfd, 20) < 0) {
        perror("listen");
        exit(1);
    }
    return sockfd;
}

char ch_char(char c) {
    if (c >= 'a' && c <= 'z') c -= 32;
    return c;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int sockfd = GetSocket(atoi(argv[1]));
    int max_fd = sockfd;
    fd_set r_fds, all_fds;
    FD_ZERO(&all_fds);
    FD_SET(sockfd, &all_fds);
    while (1) {
        r_fds = all_fds;
        int cnt = select(max_fd + 1, &r_fds, NULL, NULL, NULL);
        int fd;
        if (FD_ISSET(sockfd, &r_fds)) {
            fd = accept(sockfd, NULL, NULL);
            if (fd < 0) {
                perror("accept");
                continue;
            }
            FD_SET(fd, &all_fds);
            cnt--;
        }
        for (int i = sockfd + 1; cnt && i <= max_fd; i++) {
            if (FD_ISSET(i, &r_fds)) {
                cnt--;
                char data[1024] = {0};
                int ret;
                if ((ret = recv(i, data, sizeof(data), 0)) < 0) {
                    perror("recv");
                    FD_CLR(i, &all_fds);
                    close(i);
                    continue;
                } else if (ret == 0) {
                    printf("peer close connection\n");
                    FD_CLR(i, &all_fds);
                    close(i);
                } else {
                    printf("recv : %s\n", data);
                    for (int j = 0; data[j]; j++) {
                        if (data[j] >= 'a' && data[j] <= 'z') data[j] -= 32;
                    }
                    send(i, data, strlen(data), 0);
                }
            } 
        }
        max_fd = max(max_fd, fd);
    }
    return 0;
}
