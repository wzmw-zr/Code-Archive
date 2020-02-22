/*************************************************************************
	> File Name: 3.pthread.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月08日 星期六 09时50分52秒
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

void *show_get(void *arg) {
    printf("child thread get arg is %d\n", *((int *) arg));
    pthread_exit((void *) 0);
}

int main() {
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    void *stack_address = malloc(1024);
    int stack_size = 1024;
    pthread_attr_setstack(&attr, &stack_address, stack_size);
    int arg;
    printf("arg = ");
    scanf("%d", &arg);
    if (pthread_create(&tid, &attr, show_get, &arg)) {
        printf("child thread create failed\n");
        return -1;
    }
    printf("main thread get child thread id %lld\n", tid);
    pthread_attr_destroy(&attr);
    return 0;
}
