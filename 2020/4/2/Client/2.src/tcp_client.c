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

void Login(char *name, int sockfd) {
    int ret;
    User user;
	strcpy(user.name, name);
    if ((ret = send(sockfd, (void *) &user, sizeof(user), 0)) < 0) {
        perror("send");
        close(sockfd);
        exit(1);
    } else if (ret == 0) {
        printf("Access denied\n");
        close(sockfd);
        exit(1);
    }
}

// 处理服务端发来的信息
void HandleMessage(int sockfd, Message *msg) {
    switch (msg->type) {
        // -1表示用户已经存在
        case -1: {
            fprintf(stderr, "you have already log in!\n");
            close(sockfd);
            exit(1);
        } break;
        // 0表示用户登录成功
        case 0: {
            printf("welcome!\n");
        } break;
        // 1表示公发信息
        case 1: {
            printf("%d %s: %s\n", msg->type, msg->name, msg->data);
        } break;
        // 2表示私发信息
        case 2: {
            printf("%d %s: %s\n", msg->type, msg->name, msg->data);
        } break;
        // 3表示公发文件
        case 3: {
            printf("This is a public file!\n");
        } break;
        // 4表示私发文件
        case 4: {
            printf("This is a private file!\n");
        } break;
        // 5表示收到的是请求的在线用户的信息
        case 5 : {
            printf("%s\n", msg->data);
        } break;
        default:
            break;
    }
}


Message ParseLine(char *line, char *name) {
    Message msg;
    memset((void *) &msg, 0,  sizeof(msg));
    // line[0] == '@'表明这是一个私发信息
    if (line[0] == '@') {
        char *np = strchr(line, ' ');
        // 私发对象的名字
        snprintf(msg.target, np - line, "%s", line + 1);
        msg.type = 2;
        strcpy(msg.name, name);
        // 私发的信息
        strcpy(msg.data, np + 1);
        return msg;
    } else if (line[0] == '#') {
        // #1表示获取当前所有在线用户名字
        if (line[1] == '1') {
            msg.type = 5;
            strcpy(msg.name, name);
            return msg;
        } else if (line[1] == '2') {
            // 表示公发信息
            // TO DO：
            printf("send file\n");
            msg.type = 4;
            strcpy(msg.name, name);
            return msg;
        }
    } else {
        // 公发信息
        msg.type = 1;
        strcpy(msg.name, name);
        strcpy(msg.data, line);
        printf("send to all: data = %s\n", msg.data);
        return msg;
    }
}

void SendMessage(int sockfd, Message *msg) {
    int len = sizeof(Message);
    if (send(sockfd, (void *) msg, len, 0) <= 0) {
        perror("send");
        return ;
    }
}