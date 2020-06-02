/*************************************************************************
	> File Name: client.c
	> Author: suyelu
	> Mail: suyelu@haizeix.com
	> Created Time: 六  3/28 14:51:21 2020
 ************************************************************************/


#include<head.h>
//#include "udp_client.h"

int main(int argc, char **argv) {
    char msg[512] = {0};
    int sockfd, port;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s ip port\n", argv[0]);
        return 1;
    }
    port = atoi(argv[2]);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    scanf("%s", msg);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    while (1) { 
        sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&server, sizeof(server));
    }
    close(sockfd);
    return 0;
} 
