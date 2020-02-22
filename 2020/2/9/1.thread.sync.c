/*************************************************************************
> File Name: 1.thread.sync.c
> Author:赵睿 
> Mail: 1767153298@qq.com
> Created Time: 2020年02月09日 星期日 08时34分24秒
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

sem_t sem_pro, sem_cus;

void *produce(void *arg) {
    int pro_num, cus_num;
    while (1) {
        for (int i = 1; i <= 2; i++) {
            sem_wait(&sem_pro);
            sem_post(&sem_cus);
        } 
        sem_getvalue(&sem_pro, &pro_num);
        sem_getvalue(&sem_cus, &cus_num);
        printf("produce pro_num %d, cus_num, %d\n", pro_num, cus_num);
        sleep(1);
    }
    pthread_exit((void *) 0);
}

void *custom(void *arg) {
    int pro_num, cus_num;
    while (1) {
        sem_wait(&sem_cus);
        sem_post(&sem_pro);
        sem_getvalue(&sem_pro, &pro_num);
        sem_getvalue(&sem_cus, &cus_num);
        printf("customer pro_num %d, cus_num, %d\n", pro_num, cus_num);
        sleep(1);
    }
    pthread_exit((void *) 0);
}


int main() {
    pthread_t producer, customer;
    int *pro_ret, *cus_ret;
    sem_init(&sem_pro, 0, 10);
    sem_init(&sem_cus, 0, 0);
    if (pthread_create(&producer, NULL, produce, NULL)) {
        printf("cannot create producer thread\n");
        return -1;
    }
    if (pthread_create(&customer, NULL, custom, NULL)) {
        printf("cannot create customer thread\n");
        return -1;
    }
    if (pthread_join(producer, (void *) pro_ret)) {
        printf("cannot join producer\n");
        return -1;
    }
    if (pthread_join(customer, (void *) cus_ret)) {
        printf("cannot join customer\n");
        return -1;
    }
    return 0;
}
