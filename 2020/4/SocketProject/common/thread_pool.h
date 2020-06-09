/*************************************************************************
	> File Name: thread_pool.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月09日 星期二 18时14分50秒
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include "./head.h"
#define MAX_TASK 100
#define MAX_THREAD 10

struct task_queue {
    int sum;
    int epollfd;
    struct User **team;
    int head;
    int tail;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

void task_queue_init(struct task_queue *taskQueue, int sum, int epollfd);
void task_queue_push(struct task_queue *taskQueue, struct User *user);
struct User * task_queue_pop(struct task_queue *taskQueue);
void *thread_run(void *arg);

#endif
