/*************************************************************************
	> File Name: 3.client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月23日 星期一 19时10分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s IP port\n", argv[0]);
        exit(1);
    }
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &(server.sin_addr)) == 0) {
        perror(argv[1]);
        exit(1);
    }
    printf("inet_aton successfully!\n");
    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }
    char info[] = "this is client.\n";
    if (send(sockfd, (void *) info, strlen(info), 0) == -1) {
        perror("send");
        exit(1);
    }
    printf("send successfully!\n");
    close(sockfd);
    return 0;
}
