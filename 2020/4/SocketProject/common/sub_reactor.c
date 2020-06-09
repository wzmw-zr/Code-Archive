/*************************************************************************
	> File Name: sub_reactor.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月09日 星期二 19时52分51秒
 ************************************************************************/


#include "head.h"
#define MAX 50

void *sub_reactor(void *arg) {
    struct task_queue *taskQueue = (struct task_queue *) arg;
    pthread_t *tid = (pthread_t *) calloc(MAX_THREAD, sizeof(pthread_t));
    for (int i = 0; i < MAX_THREAD; i++) {
        pthread_create(&tid[i], NULL, thread_run, (void *) taskQueue);
    }
    struct epoll_event ev, events[MAX];
    int nfds;
    while (1) {
        DBG(RED"Sub Reactor : "NONE" Epoll waiting ...\n");
        nfds = epoll_wait(taskQueue->epollfd, events, MAX, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(1);
        }
        for (int i = 0; i < nfds; i++) {
            struct User *user = (struct User *) events[i].data.ptr;
            DBG(L_YELLOW"events[n].data.ptr->name = %s\n"NONE, user->name);
            if (events[i].events & EPOLLIN) {
                task_queue_push(taskQueue, user);
            }
        }
    }
    return NULL;
}
