/*************************************************************************
	> File Name: 2.socket.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月22日 星期日 20时04分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen;
    port = atoi(argv[1]);
    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    printf("Socket before bind\n");
    if (bind(server_listen, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }
    printf("Socket before listen\n");
    if (listen(server_listen, 20) < 0) {
        perror("listen");
        exit(1);
    }
    while (1) {
        int sockfd;
        printf("Socket before listen\n");
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accpet");
            close(sockfd);
            continue;
        }
        pid_t pid;
        if ((pid = fork()) < 0) {
            perror("fork");
            continue;
        }
        if (pid == 0) {
            close(server_listen);
            char name[20] = {0};
            if (recv(sockfd, name, sizeof(name), 0) <= 0) {
                perror("recv");
                close(sockfd);
                exit(0);
            }
            printf("name : %s\n", name);
            close(sockfd);
            exit(1);
        }
        close(sockfd);
    }
    close(server_listen);
    return 0;
}
