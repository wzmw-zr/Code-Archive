/*************************************************************************
	> File Name: 2.thread.sync.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月09日 星期日 09时15分30秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<mqueue.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/mman.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int number;

void *produce(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (!number) pthread_cond_signal(&cond);
        if (number == 10) pthread_cond_wait(&cond, &mutex);
        number++;
        printf("producer number %d\n", number);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit((void *) 0);
}

void *custom(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (!number) pthread_cond_wait(&cond, &mutex);
        if (number == 10) pthread_cond_signal(&cond);
        number--;
        printf("customer number %d\n", number);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    pthread_exit((void *) 0);
}

int main() {
    pthread_t producer, customer;
    int *pro_ret, *cus_ret;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    number = 0;
    if (pthread_create(&producer, NULL, produce, NULL)) {
        printf("cannot creat producer\n");
        return -1;
    }
    if (pthread_create(&customer, NULL, custom, NULL)) {
        printf("cannot create customer\n");
        return -1;
    }
    if (pthread_join(producer, (void *) pro_ret)) {
        printf("cannot get producer return value\n");
        return -1;
    }
    if (pthread_join(customer, (void *) cus_ret)) {
        printf("cannot get customer return value\n");
        return -1;
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
