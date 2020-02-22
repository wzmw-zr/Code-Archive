/*************************************************************************
	> File Name: 9.epoll.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 18时12分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/epoll.h>

int main() {
    int epdp = epoll_create(10);
    printf("%d\n", epdp);
    int dp = open("new.txt", O_RDWR, S_IRUSR | S_IWUSR);
    struct epoll_event *event = (struct epoll_event *) calloc(1, sizeof(struct epoll_event));
    event->events = EPOLLIN;
    (event->data).fd = dp;
    if (epoll_ctl(epdp, EPOLL_CTL_ADD, dp, event) == -1) {
        printf("add failed!\n");
        return -1;
    }
    printf("successfully add\n");
    return 0;
}
