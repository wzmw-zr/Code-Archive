/*************************************************************************
	> File Name: tcp_server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 16时43分29秒
 ************************************************************************/
 #include "../1.include/head.h"
 #include "../1.include/message.h"
 #include "../1.include/tcp_server.h"

 pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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


User *UserExist(char *name) {
    User *head = start;
    while (head->next && strcmp(name, head->next->name)) head = head->next;
    if (head->next) return head->next;
    return NULL;
}

void AddUser(User *user) {
    user->next = start->next;
    start->next = user;
}

void Deleteuser(char *name) {
    User *head = start, *tmp;
    while (head->next && strcmp(name, head->name)) head = head->next;
    if (!head->next) return ;
    tmp = head->next;
    head->next = tmp->next;
    free(tmp);
}

// 给单独的用户发送信息
void SendOne(Message *msg, User *user) {
    int fd = user->sockfd;
    if (send(fd, (void *) msg, sizeof(Message), 0) <= 0) {
        perror("send");
        Deleteuser(user->name);
        close(fd);
    }
}

// 公发信息，遍历用户链表实现
void SendAll(Message *msg) {
    User *head = start;
    while (head->next) {
        SendOne(msg, head->next);
        head = head->next;
    }
}

// 处理用户发来的信息
void HandleMessage(int fd, Message msg) {
    Message tmp = msg;
    switch (tmp.type) {
        // 1表示公发信息
        case 1: SendAll(&tmp); break;
        // 2表示私发信息
        case 2: {
            User *to = UserExist(tmp.target);
            if (send(to->sockfd, (void *) &tmp, sizeof(tmp), 0) <= 0) {
                perror("send");
            }
        } break;
        // 3表示公发文件
        case 3: SendAll(&tmp); break;
        // 4表示私发文件
        case 4: {
            User *to = UserExist(tmp.target);
            if (send(to->sockfd, (void *) &tmp, sizeof(tmp), 0) <= 0) {
                perror("send");
            }
        } break;
        // 5表示用户请求当前在线用户的信息
        case 5: {
            User *head;
            while (head->next) {
                msg.type = 5;
                strcpy(msg.data, head->next->name);
                if (send(fd, (void *) &tmp, sizeof(tmp), 0) <= 0) {
                    perror("send");
                }
                head = head->next;
            }
        } break;
    }
}