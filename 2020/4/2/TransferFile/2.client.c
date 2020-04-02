/*************************************************************************
	> File Name: 2.client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月02日 星期四 14时55分28秒
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
    long size;
    char name[256];
    char buf[4096];
} Message;

int GetSocket(char *ip, char *port) {
    int sockfd;
    struct sockaddr_in address;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(port));
    if (inet_aton(ip, &(address.sin_addr)) < 0) {
        perror("inet_aton");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("connect");
        exit(1);
    }
    return sockfd;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s ip port\n", argv[0]);
        exit(1);
    }
    int sockfd = GetSocket(argv[1], argv[2]);
    char buf[100] = {0};
    char name[256] = {0};
    Message msg;
    while (1) {
        scanf("%[^\n]s", buf);
        getchar();
        if (!strncmp("send ", buf, 5)) {
            strcpy(name, buf + 5);
        } else {
            fprintf(stderr, "Invalid command");
            continue;
        }
        FILE *fp = NULL;
        size_t size;
        if ((fp = fopen(name, "rb")) == NULL) {
            perror("fopen");
            continue;
        }
        fseek(fp, 0L, SEEK_END);
        msg.size = ftell(fp);
        strcpy(msg.name, "haha");
        fseek(fp, 0L, SEEK_SET);
        while ((size = fread(msg.buf, 1, 4096, fp))) {
            send(sockfd, (void *) &msg, sizeof(msg), 0);
            memset(msg.buf, 0, sizeof(msg.buf));
        }
        printf("After Send\n");
    }
    return 0;
}
