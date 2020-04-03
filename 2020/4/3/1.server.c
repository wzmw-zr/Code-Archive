/*************************************************************************
	> File Name: 1.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月03日 星期五 07时42分17秒
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
    if (setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (void *) &val, sizeof(val)) < 0) {
        perror("setsockopt");
        exit(1);
    }
    return sockfd;
}

void HandleMessage(int fd) {
    Message msg, msg_t, msg_pre;
    int offset = 0, recv_len, incomplete = 0, msg_size = sizeof(msg);
    long write_size = 0;
    while (1) {
        if (incomplete) {
            memcpy((void *) &msg, (void *) &msg_pre, incomplete);
            offset = incomplete;
        }
        incomplete = 0;
        int cnt = 0;
        while ((recv_len = recv(fd, (void *) &msg_t, msg_size, 0)) > 0) {
            cnt++;
            if (offset + recv_len == msg_size) {
                memcpy((void *) &msg, (void *) &msg_t, recv_len);
                offset = 0;
                printf("full package!\n");
                break;
            } else if (offset+ recv_len < msg_size) {
                memcpy((void *) &msg + offset, (void *) &msg_t, recv_len);
                offset += recv_len;
                printf("part package!\n");
            } else if (offset + recv_len > msg_size) {
                int new_offset = offset + recv_len - msg_size;
                int last_len = msg_size - offset;
                memcpy((void *) &msg + offset, (void *) &msg_t, last_len);
                memcpy((void *) &msg_pre, (void *) &msg_t + last_len, new_offset);
                offset = 0;
                incomplete = new_offset; 
                printf("Linked package\n");
                break;
            }
        }
        char path[256] = "./tmp/";
        if (recv_len > 0 || (recv_len == 0 && cnt)) {
            strncat(path, msg.name, strlen(msg.name));
            FILE *fp = NULL;
            fp = fopen(path, "ab+");
            if (write_size + sizeof(msg.data) < msg.filesize) {
                write_size += fwrite((void *) msg.data, 1, sizeof(msg.data), fp); 
                printf("write_size = %d\n", write_size);
            } else {
                write_size += fwrite((void *) msg.data, 1, msg.filesize - write_size, fp);
                printf("write_size = %d\n", write_size);
                write_size = 0;
            } 
        }
        if (recv_len == 0 && !cnt) {
            printf("Peer socket closed!\n");
            exit(1);
        }
        if (recv_len < 0) {
            perror("recv");
            exit(1);
        }
    }
}

int main() {
    int sockfd = GetSocket();
    while (1) {
        int fd;
        pid_t pid;
        if ((fd = accept(sockfd, NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            HandleMessage(fd);
            exit(1);
        } else {
            int status;
            wait(&status);
        }
    }
    close(sockfd);
    return 0;
}
