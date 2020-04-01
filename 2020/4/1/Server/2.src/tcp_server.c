/*************************************************************************
	> File Name: tcp_server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 16时43分29秒
 ************************************************************************/
 #include "../1.include/head.h"
 #include "../1.include/message.h"
 #include "../1.include/tcp_server.h"

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

int GetSocket(char *port) {
    int sockfd;
    struct sockaddr_in address;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    return sockfd;
}

void BindAndListen(int sockfd, int port) { 
    struct linger val;
    val.l_onoff = 1;
    val.l_linger = 0; 
    if (setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (void *) &val, (socklen_t ) sizeof(val)) == -1) {
        perror("setsockopt");
        exit(1);
    }
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind");
        exit(1);
    }
    if (listen(sockfd, 20) == -1) {
        perror("listen");
        exit(1);
    }
}

void UserLogin(char *name) {
    printf("%s\n", name);
}
