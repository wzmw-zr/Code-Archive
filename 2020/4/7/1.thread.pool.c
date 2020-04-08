/*************************************************************************
	> File Name: 1.thread.pool.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月07日 星期二 10时20分39秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/mman.h>

typedef struct threadpool_task_t {
    void *(*function)(void *);
    void *arg;
} threadpool_task_t;

typedef struct threadpool_task_queue {
    threadpool_task_t *task_queue;
    int front, rear, cnt, size;
} threadpool_task_queue;

threadpool_task_queue *GetTaskQueue(int size) {
    threadpool_task_queue *que = (threadpool_task_queue *) calloc(sizeof(threadpool_task_queue), 1);
    que->size = size;
    que->front = que->rear = que->cnt = 0;
    que->task_queue = (threadpool_task_t *) calloc(sizeof(threadpool_task_t), size);
    return que;
}

threadpool_task_queue *enlarge() {
    return NULL;
}

typedef struct pthreadpool_t {
    pthread_mutex_t mutex;
    pthread_mutex_t busy_thread_counter;

    pthread_cond_t queue_full;
    pthread_cond_t queue_empty;

    pthread_t *tids;
    pthread_t manager_tid;

    int min_thread_num;
    int max_thread_num;
    int live_thread_num;
    int busy_thread_num;
    int wait_thread_exit_num;

    threadpool_task_queue task_queue;

    int open;
} pthreadpool_t;

int main() {
    return 0;
}
