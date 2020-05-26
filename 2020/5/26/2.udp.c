/*************************************************************************
	> File Name: 2.udp.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月26日 星期二 20时09分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int GetSocket() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    return sockfd;
}

void BindAndListen(int sockfd, int port) {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind");
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[1]);
    int sockfd = GetSocket();
    if (sockfd == -1) {
        perror("GetSocket");
        exit(1);
    }
    BindAndListen(sockfd, port);
    return 0;
}
