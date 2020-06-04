/*************************************************************************
	> File Name: 1.client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月04日 星期四 19时51分16秒
 ************************************************************************/

#include "../common/head.h"
#include "../common/color.h"
#include "../common/common.h"
#include "../common/udp_client.h"

char server_ip[20];
int server_port;
char *config = "./football.conf";
int sockfd;

int main(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "h:p:")) != -1) {
        switch (opt) {
            case 'h' : 
                strcpy(server_ip, optarg);
                break;
            case 'p' : 
                server_port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s [-h host] [-p port]\n", argv[0]);
                exit(1);
        }
    }

    argc -= (optind - 1);
    argv += (optind - 1);
    
    if (argc > 1) {
        fprintf(stderr, "Usage : %s [-h host] [-p port]\n", argv[0]);
        exit(1);
    }

    if (!server_port) server_port = atoi(get_value(config, "SERVERPORT"));
    if (!strlen(server_ip)) strcpy(server_ip, get_value(config, "SERVERIP"));
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    server.sin_addr.s_addr = inet_addr(server_ip);

    socklen_t len = sizeof(server);

    printf(GREEN"INFO"NONE" : %s : %d\n", server_ip, server_port);

    if ((sockfd = socket_udp()) < 0) {
        perror("socket_udp");
        exit(1);
    }

    char msg[512] = "hello";

    sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *) &server, len);


    recvfrom(sockfd, msg, sizeof(msg), 0, (struct sockaddr *) &server, &len);
    printf("%s\n", msg);

    return 0;
}
