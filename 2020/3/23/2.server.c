/*************************************************************************
	> File Name: 2.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月23日 星期一 18时32分34秒
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

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage; %s IP port\n", argv[0]);
        exit(1);
    }
    int sock_listen;
    if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock_listen, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("bind");
        exit(1);
    }
    if (listen(sock_listen, 20) == -1) {
        perror("listen");
        exit(1);
    }
    while (1) {
        struct sockaddr_in client;
        int len = sizeof(client);
        int socketfd;
        if ((socketfd = accept(sock_listen, (struct sockaddr *) &client, &len)) == -1) {
            perror("accept");
            close(sock_listen);
            exit(1);
        }
        printf("client ip address = %s\n", inet_ntoa(client.sin_addr));
        char buffer[513] = {0};
        size_t length = 512, l;
        while ((l = recv(socketfd, (void *) buffer, length, 0)) > 0) {
            write(1, (void *) buffer, l);
        }
        if (len == -1) {
            perror("recv");
            close(socketfd);
            exit(1);
        }
        close(socketfd);
    }
    close(sock_listen);
    return 0;
}
