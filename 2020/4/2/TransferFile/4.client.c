/*************************************************************************
	> File Name: 4.client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月02日 星期四 17时31分48秒
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
#include<sys/sendfile.h>
#include<netinet/in.h>
#include<arpa/inet.h>

typedef struct Message {
    char name[256], target[256], file_path[256];
    int type;
    char data[1028];
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
    if (inet_aton("127.0.0.1", &(address.sin_addr)) < 0) {
        perror("inet_aton");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("connect");
        exit(1);
    }
    return sockfd;
}

int main() {
    int sockfd = GetSocket();
    int fd = open("./1.png", O_RDWR);
    Message msg;
    strcpy(msg.file_path, "2.png");
    msg.type = 3;
    while (1) {
        int len;
        if ((len = read(fd, msg.data, 1024)) <= 0) break;
        if (send(sockfd, &msg, sizeof(msg), 0) <= 0) break;
        memset(msg.data, 0, sizeof(msg.data));
    }
    close(fd);
    close(sockfd);
    return 0;
}

