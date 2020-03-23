/*************************************************************************
	> File Name: 1.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月23日 星期一 18时12分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
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
    if (!inet_aton(argv[1], &(server.sin_addr))) {
        perror(argv[1]);
        exit(1);
    }
    if (bind(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("bind");
        exit(1);
    }
    if (listen(sockfd, 20) == -1) {
        perror("listen");
        exit(1);
    }
    printf("last action!\n");
    close(sockfd);
    return 0;
}
