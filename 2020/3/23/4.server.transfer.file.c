/*************************************************************************
	> File Name: 4.server.transfer.file.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月23日 星期一 20时14分48秒
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
#include<sys/wait.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MSGSIZE 512
int GetSocket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    return sockfd;
}

struct sockaddr_in GetSockAddrIN(char *port) {
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    server.sin_addr.s_addr = INADDR_ANY;
    return server;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int socket_listen = GetSocket(); 
    struct sockaddr_in server = GetSockAddrIN(argv[1]);
    if (bind(socket_listen, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("bind");
        exit(1);
    }
    if (listen(socket_listen, 20) == -1) {
        perror("listen");
        exit(1);
    }
    while (1) {
        struct sockaddr_in client;
        int sockfd, size = sizeof(client);
        if ((sockfd = accept(socket_listen, (struct sockaddr *) &client, &size)) == -1) {
            perror("accept");
            exit(1);
        }  
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        }
        if (pid) {
            int status;
            if (wait(&status) == -1) {
                perror("wait");
                exit(1);
            }
            continue;
        }
        printf("client IP address: %s\n", inet_ntoa(client.sin_addr));
        char msg[MSGSIZE + 5] = {0};
        int msg_len;
        while ((msg_len = recv(sockfd, msg, MSGSIZE, 0)) > 0) {
            write(1, msg, msg_len);
        }
        close(sockfd);
        if (msg_len == -1) {
            perror("recv");
            exit(1);
        }
    }
    close(socket_listen);
    return 0;
}
