/*************************************************************************
	> File Name: udp_epoll.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月04日 星期四 19时07分50秒
 ************************************************************************/

#include "./head.h"
#include "./color.h"
#include "./common.h"
#include "./udp_client.h"
#include "./udp_server.h"

extern int port;

void add_event(int epoll_fd, int fd, int events) {
    struct epoll_event ev;
    ev.events = events;
    ev.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev);
}

void delete_event(int epoll_fd, int fd, int events) {
    struct epoll_event ev;
    ev.events = events;
    ev.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, &ev);
}

int udp_connect(int epoll_fd, struct sockaddr * server_addr) {
    int sockfd;
    if ((sockfd = socket_create_udp(8888)) < 0) {
        perror("socket");
        return -1;
    }
    DBG(GREEN"INFO"NONE" : Before connect.\n");
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr))) {
        perror("connect");
        return -1;
    }
    DBG(GREEN"INFO"NONE" : After connect.\n");
    int ret = send(sockfd, "Login!", sizeof("Login!"), 0);
    DBG(RED"RET = %d\n"NONE, ret);
    add_event(epoll_fd, sockfd, EPOLLIN);
    return sockfd;
}

int udp_accept(int epoll_fd, int sockfd) {
    struct sockaddr_in client;
    int new_fd, ret;
    char msg[512] = {0};
    socklen_t len = sizeof(client);
    ret = recvfrom(sockfd, msg, sizeof(msg), 0, (struct sockaddr *) &client, &len);
    if (ret < 0) return -1;
    DBG(GREEN"INFO"NONE" : %s : %d login!\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    new_fd = udp_connect(epoll_fd, (struct sockaddr *) &client);
    return new_fd;
}
