/*************************************************************************
	> File Name: client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月31日 星期二 20时50分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/wait.h>
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
    inet_aton("127.0.0.1", &(address.sin_addr));
    connect(sockfd, (struct sockaddr *) &address, sizeof(address));

    return 0;
}
