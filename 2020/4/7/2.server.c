/*************************************************************************
	> File Name: 2.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月07日 星期二 18时17分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/mman.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include "./color.h"
#define MAXTASK 100
#define MAXTHREAD 20

char ch_char(char c) {
    if (c >= 'a' && c <= 'z') c -= 32;
    return c;
}

void do_echo(int fd) {
    char buf[512] = {0}, ch;
    int ind = 0;
    while (1) {
        if (recv(fd, &ch, sizeof(char), 0) <= 0) break;
        if (ind < sizeof(buf)) buf[ind++] = ch_char(ch);
        if (ch == '\n') {
            send(fd, buf, ind, 0); 
            ind = 0;
            continue;
        }
    }
}

typedef struct {
    int sum;
    int *fd;
    int head, tail;
    pthread_mutex_t mutex;
    pthread_cond_t full;
    pthread_cond_t empty;
} TaskQueue;

void TaskQueueInit(TaskQueue *queue, int sum) {
    queue->sum = sum;
    queue->fd = (int *) calloc(sizeof(int), sum);
    queue->head = queue->tail = 0;
    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->full, NULL);
    pthread_cond_init(&queue->empty, NULL);
}

void TaskQueuePush(TaskQueue *queue, int fd) {
    pthread_mutex_lock(&queue->mutex);
    while ((queue->tail + 1) % queue->sum == queue->head) {
        printf(RED"<QueueEnd>\n"NONE);
        pthread_cond_wait(&queue->full, &queue->mutex);
    } 
    printf(GREEN"<TaskPush>"NONE":%d\n", fd);
    queue->fd[queue->tail] = fd;
    queue->tail = (queue->tail + 1) % queue->sum;
    pthread_mutex_unlock(&queue->mutex);
    pthread_cond_signal(&queue->empty);
}

int TaskQueuePop(TaskQueue *queue) {
    pthread_mutex_lock(&queue->mutex);
    while (queue->head == queue->tail) {
        printf(RED"Queue Empty!"NONE"\n");
        pthread_cond_wait(&queue->empty, &queue->mutex);
    }
    printf(GREEN"<TaskPop>"NONE"\n");
    int ret = queue->fd[queue->head]; 
    queue->head = (queue->head + 1) % queue->sum;
    pthread_mutex_unlock(&queue->mutex);
    pthread_cond_signal(&queue->full);
    return ret;
}


int GetSokcet(int port) {
    int sockfd;
    struct sockaddr_in address;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0))  < 0) {
        perror("socket");
        exit(1);
    } 
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind");
        exit(1);
    }
    if (listen(sockfd, 20) < 0) {
        perror("listen");
        exit(1);
    }
    return sockfd;
}

void *thread_run(void *arg) {
    pthread_t tid = pthread_self();
    pthread_detach(tid);
    TaskQueue *queue = (TaskQueue *) arg;
    while (1) {
        int fd = TaskQueuePop(queue);
        do_echo(fd);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen, fd;
    port = atoi(argv[1]);
    server_listen = GetSokcet(port);
    TaskQueue queue;
    TaskQueueInit(&queue, MAXTASK);
    pthread_t *tid = (pthread_t *) calloc(sizeof(pthread_t), MAXTHREAD);
    /*pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    */
    for (int i = 0; i < MAXTHREAD; i++) {
        pthread_create(&tid[i], NULL, thread_run, (void *) &queue); 
    }
    while (1) {
        if ((fd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }
        printf(BLUE"<login>"NONE"\n");
        TaskQueuePush(&queue, fd);
    }
    return 0;
}

