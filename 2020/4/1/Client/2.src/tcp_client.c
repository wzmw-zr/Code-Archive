/*************************************************************************
	> File Name: tcp_client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 16时04分40秒
 ************************************************************************/

#include "../1.include/head.h"
#include "../1.include/tcp_client.h"

char *get_value(char *path, char *key) {
    FILE *fp = fopen(path, "r");
    char *line = calloc(sizeof(char), 50);
    size_t len = sizeof(line);
    char *ret = NULL;
    while (getline(&line, &len, fp) != -1) {
        if (strncmp(line, key, strlen(key)) && line[strlen(key)] != '=') continue;
        line[strlen(line) - 1] = '\0';
        ret = strdup(strchr(line, '=') + 1);
        break;
    }
    free(line);
    return ret;
}

int GetSocket() {
    int sockfd;
    if (sockfd = socket(AF_INET, SOCK_STREAM, 0) == -1) {
        perror("socket");
        exit(1);
    }
    return sockfd;
}

struct sockaddr_in GetAddress(char *ip, char *port) {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(port));
    if (inet_aton(ip, &(address.sin_addr)) == -1) {
        perror("inet_aton");
        exit(1);
    }
    return address;
}

void ConnectServer(int sockfd, struct sockaddr_in address) {
    if (connect(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        perror("connect");
        exit(1);
    }
}

void ParseLine(char *line, char *name) {
}

void Login(char *name, int sockfd) {
    int ret;
    if ((ret = send(sockfd, (void *) name, strlen(name), 0)) < 0) {
        perror("send");
        close(sockfd);
        exit(1);
    } else if (ret == 0) {
        printf("Access denied\n");
        close(sockfd);
        exit(1);
    }
}
