/*************************************************************************
	> File Name: 1.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月02日 星期四 14时47分22秒
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
#include<sys/wait.h>
#include<sys/sendfile.h>
#include<netinet/in.h>
#include<arpa/inet.h>

typedef struct Message {
    long size;
    char name[256];
    char buf[4096];
} Message;

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
    return sockfd;
}

void child_do(int fd) {
    size_t recv_size;
    Message packet_t, packet, packet_pre;
    int packet_size = sizeof(Message);
    long filesize;
    int offset = 0, flag = 0, cnt = 0;
    printf("Before recv\n");
    FILE *fp = NULL;
    while (1) {
        if (flag) {
            memcpy(&packet, &packet_pre, flag);
            offset = flag;
        }
        flag = 0;
        while ((recv_size = recv(fd, (void *) &packet_t, packet_size, 0)) > 0) {
            if (offset + recv_size == packet_size) {
                memcpy((char *) &packet + offset, (char *) &packet_t, recv_size);
                offset = 0;
                printf("full packet!\n");
                break;
            } else if (offset + recv_size < packet_size) {
                memcpy((char *) &packet + offset, (char *) &packet_t, recv_size);
                offset += recv_size;
                printf("part packet!\n");
            } else if (offset + recv_size > packet_size) {
                memcpy((char *) &packet + offset, (char *) &packet_t, packet_size - offset);
                flag = recv_size - (packet_size - offset);
                memcpy((char *) &packet_pre, (char *) &packet_t + packet_size - offset, flag);
                printf("linked packet!\n");
                break;
            }
        }
        if (!cnt) {
            cnt++;
            printf("recv %s with size = %d\n", packet.name, packet_size);
            if ((fp = fopen(packet.name, "wb")) == NULL) {
                perror("fopen");
                break;
            } 
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(1);
    }
    int sockfd = GetSocket() , port;
    pid_t pid;
    port = atoi(argv[1]);
    /*while (1) {
        if ((fd = accept(sockfd, NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }
    }*/
    Message msg;
    FILE *fp = NULL;
    while (1) {
        int fd;
        if ((fd = accept(sockfd, NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            child_do(fd);
            exit(0);
        } else {
            int status;
            wait(&status);
            close(fd);
        }
    }
    close(sockfd);
    return 0;
}
