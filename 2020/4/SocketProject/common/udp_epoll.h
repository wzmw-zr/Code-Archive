/*************************************************************************
	> File Name: udp_epoll.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月04日 星期四 19时24分51秒
 ************************************************************************/

#ifndef _UDP_EPOLL_H
#define _UDP_EPOLL_H
void add_event(int epool_fd, int fd, int events);
void del_event(int epool_fd, int fd, int events);
int udp_connect(int epoll_fd, struct sockaddr *server_addr);
int udp_accept(int epoll_fd, int fd);
#endif
