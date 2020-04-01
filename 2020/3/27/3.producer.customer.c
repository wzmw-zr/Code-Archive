/*************************************************************************
	> File Name: 3.producer.customer.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月27日 星期五 16时46分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int number;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *custom(void *arg){
    while (1) {
        pthread_mutex_lock(&mutex);
        if (number <= 5) pthread_cond_wait(&cond, &mutex);
        printf("this is customer thread %lu, number = %d\n", pthread_self(), number);
        number--;
        pthread_mutex_unlock(&mutex);
        if (number < 10) pthread_cond_signal(&cond);
        sleep(2);
    }
    return NULL;
}


int main(int argc, char **argv) {
    pthread_t producer, customer;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&customer, &attr, custom, NULL);
    while (1) {
        pthread_mutex_lock(&mutex);
        if (number >= 10) pthread_cond_wait(&cond, &mutex);
        number++;
        printf("this is producer thread %lu, number = %d\n", pthread_self(), number);
        if (number > 5) pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return 0;
}
