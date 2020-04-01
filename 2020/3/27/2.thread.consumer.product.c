/*************************************************************************
	> File Name: 2.thread.consumer.product.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月27日 星期五 15时39分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int goods = 0;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *consumer(void *arg) {
    pthread_mutex_lock(&mutex);
    if (!goods) pthread_cond_wait(&cond, &mutex);
    goods--;
    int *id = (int *) arg;
    printf("this is the %d thread\n", *id);
    pthread_mutex_unlock(&mutex);
    sleep(1);
}

int main(int argc, char **argv) {
    pthread_t tid[10];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    for (int i = 0; i < 10; i++) {
        int errno;
        int id = i;
        if ((errno = pthread_create(&tid[i], &attr, consumer, (void *) &id))) {
            fprintf(stderr, "%s\n", strerror(errno));
            exit(1);
        }
    }
    while (1) {
        goods++;
        pthread_cond_broadcast(&cond);
        sleep(2);
    }
    return 0;
}
