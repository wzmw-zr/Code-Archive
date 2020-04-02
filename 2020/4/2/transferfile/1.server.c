/*************************************************************************
	> File Name: 1.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月02日 星期四 22时13分20秒
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
    int size;
    char filename[256];
    char data[4096];
} Message;

int GetSocket(char *port) {
    int sockfd;
    struct sockaddr_in address;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(port));
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bindd");
        exit(1);
    }
    struct linger val;
    val.l_onoff = 1;
    val.l_linger = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (void *) &val, sizeof(val)) < 0) {
        perror("setsockopt");
        exit(1);
    }
    if (listen(sockfd, 20) < 0) {
        perror("listen");
        exit(1);
    }
    return sockfd;
}

void GetMessage(int fd) {
    Message msg, msg_pre, msg_t;
    int offset = 0, recv_len, incomplete = 0;
    FILE *fp = NULL;
    int msg_size = sizeof(msg);
    while (1) {
        if (incomplete) {
            memcpy((void *) &msg, (void *) &msg_pre, incomplete);
            offset = incomplete;
            incomplete = 0;
        }
        if ((recv_len = recv(fd, &msg_t, msg_size, 0)) < 0) {
            perror("recv");
            continue;
        } else if (recv_len == 0) {
            printf("Peer Closed!\n");
            exit(1);
        } else {
            if (offset + recv_len == msg_size) {
                memcpy((void *) &msg + offset, (void *) &msg_t, recv_len);
                offset = 0;
            } else if (offset + recv_len < msg_size) {
                memcpy((void *) &msg + offset, (void *) &msg_t, recv_len);
                offset += recv_len;
            } else {
                memcpy((void *) &msg + offset, (void *) &msg_t, msg_size - offset);
                offset = 0;
                incomplete = recv_len - msg_size + offset;
                memcpy((void *) &msg_pre, (void *) &msg_t + msg_size - offset, incomplete);
            }
        }
        if (offset) continue;
        printf("%s", msg.data);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int sockfd = GetSocket(argv[1]);
    while (1) {
        int fd;
        pid_t pid;
        if ((fd = accept(sockfd, NULL, NULL)) < 0) {
            perror("accept");
            continue;
        }
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Get the Message
            GetMessage(fd);
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
