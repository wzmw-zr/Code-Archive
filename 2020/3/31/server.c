/*************************************************************************
	> File Name: server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月31日 星期二 20时15分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

typedef struct FileInfo {
    char filepath[256];
    char data[1024];
} FileInfo;
 
int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(8888);
    address.sin_addr.s_addr = INADDR_ANY;
    bind(sockfd, (struct sockaddr *) &address, sizeof(address));
    listen(sockfd, 20);
    while (1) {
        int fd = accept(sockfd, NULL, NULL);
        while (1) { 
            FileInfo f_info;
            int len = sizeof(f_info);
            if (recv(fd, (void *) &f_info, len, 0) <= 0) break;
            FILE *fp = fopen(f_info.filepath, "a+");
            fputs(f_info.data, fp);
        }
        break;
    }
    return 0;
}
