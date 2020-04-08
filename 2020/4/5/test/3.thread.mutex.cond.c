/*************************************************************************
	> File Name: 3.thread.mutex.cond.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月05日 星期日 23时31分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/mman.h>

typedef struct Data {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int flag;
    char data[1024];
} Data;

Data data;

void *server(void *arg) {
    while (1) {
        pthread_mutex_lock(&data.mutex);
        while (!data.flag) pthread_cond_wait(&data.cond, &data.mutex);
        printf("<server>: %s\n", data.data);
        data.flag = 0;
        pthread_mutex_unlock(&data.mutex);
        pthread_cond_broadcast(&data.cond);
    }
    return NULL;
}

void *client(void *arg) {
    while (1) {
        pthread_mutex_lock(&data.mutex);
        while (data.flag) pthread_cond_wait(&data.cond, &data.mutex);
        printf("<client %lu>", pthread_self());
        scanf("%[^\n]s", data.data);
        getchar();
        data.flag = 1;
        pthread_mutex_unlock(&data.mutex);
        pthread_cond_broadcast(&data.cond);
    }
    return NULL;
}

int main() {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_t s_tid, c_tid[5];
    pthread_create(&s_tid, NULL, server, NULL);
    for (int i = 0; i < 5; i++) {     
        pthread_create(&c_tid[i], NULL, client, NULL);
    }
    void *retval;
    pthread_join(s_tid, &retval);
    for (int i = 0; i < 5; i++) {
        pthread_join(c_tid[i], &retval);
    }
    return 0;
}
