/*************************************************************************
	> File Name: server.c
	> Author: suyelu
	> Mail: suyelu@haizeix.com
	> Created Time: Tue 07 Apr 2020 06:40:01 PM CST
 ************************************************************************/

#include "../common/color.h"
#include "../common/common.h"
#include "../common/udp_server.h"
#include "../common/head.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int port, sockfd;
    struct sockaddr_in client;
    socklen_t addr_len = sizeof(client);
    port = atoi(argv[1]);
    if ((sockfd = socket_create_udp(port)) < 0) {
        perror("socket_create_udp");
        exit(1);
    }
    memset(&client, 0, sizeof(struct sockaddr_in));
    while (1) {
        char buffer[512] = {0};
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &client, &addr_len) > 0) {
            printf("[%s] : %s\n", inet_ntoa(client.sin_addr), buffer);
        }
        sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &client, sizeof(client));
    }
    return 0;
}
