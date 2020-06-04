/*************************************************************************
	> File Name: udp_client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月04日 星期四 18时30分22秒
 ************************************************************************/

#include "./udp_client.h"
#include "./head.h"

int socket_udp() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    return sockfd;
}
