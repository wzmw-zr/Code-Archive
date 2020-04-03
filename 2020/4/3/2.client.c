/*************************************************************************
	> File Name: 2.client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月03日 星期五 08时08分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<netinet/in.h>
#include<arpa/inet.h>

typedef struct Message {
    long filesize;
    char name[256];
    char data[4096];
} Message;

int sockfd;

void signalhandler(int sig) {
    close(sockfd);
    exit(1);
}

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
    signal(SIGINT, signalhandler);
    sockfd = GetSocket();
    FILE *fp = NULL;
    while (1) {
        char name[256] = {0};
        Message msg;
        memset((void *) &msg, 0, sizeof(msg));
        printf("Input the filepath: ");
        scanf("%s", name);
        strcpy(msg.name, name);
        if (!(fp = fopen(name, "rb"))) {
            perror("fopen");
            continue;
        }
        fseek(fp, 0, SEEK_END);
        msg.filesize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        printf("filesize = %d\n", msg.filesize);
        int whole_len = 0;
        while (!feof(fp)) {
            memset(msg.data, 0, sizeof(msg.data));
            size_t len;
            if (fread(msg.data, 1, sizeof(msg.data), fp) <= 0) continue;
            if ((len = send(sockfd, (void *) &msg, sizeof(msg), 0)) < 0) {
                perror("send");
                continue;
            } else if (len == 0) {
                printf("connect closed!\n");
                break;
            } else {
                printf("send %d bytes\n", len);
            }
            whole_len += len;
        }
        printf("whole_len = %d\n", whole_len);
    }
    fclose(fp);
    close(sockfd);
    return 0;
}
