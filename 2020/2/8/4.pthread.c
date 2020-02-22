/*************************************************************************
	> File Name: 4.pthread.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月08日 星期六 10时13分23秒
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

pthread_attr_t *create_my_thread_attr() {
    pthread_attr_t *attr = (pthread_attr_t *) calloc(1, sizeof(pthread_attr_t));
    void *stack_address = calloc(1, 1024);
    int stack_size = 1024;
    pthread_attr_setdetachstate(attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setstack(attr, stack_address, stack_size);
    return attr;
}

void *show(void *arg) {
    printf("this is child thread 2\n");
    pthread_exit((void *) 0);
}

void *show_get(void *arg) {
    printf("child thread 1 get arg %d\n", *((int *) arg));
    pthread_t tid;
    pthread_attr_t *attr = create_my_thread_attr();
    if (pthread_create(&tid, attr, show, NULL)) {
        printf("child thread 1 create child thread failed\n");
        return (void *) -1;
    }
    int *retval;
    if (pthread_join(tid, (void *)retval)) {
        printf("cannot get child thread 1 exit value\n");
        return (void *) -1;
    }
    printf("child thread 2 exit value is %d\n", *retval);
    printf("child thread 1 create child thread id %lld\n", tid);
    pthread_exit((void *) 0);
}

int main() {
    pthread_t tid;
    pthread_attr_t *attr = create_my_thread_attr();
    int arg;
    printf("arg = ");
    scanf("%d", &arg);
    if (pthread_create(&tid, attr, show_get, &arg)) {
        printf("cannot create child thread\n");
        return -1;
    }
    int *retval;
    if (pthread_join(tid, (void *)retval)) {
        printf("cannot get child thread 1 exit value\n");
        return -1;
    }
    printf("child thread 1 exit value is %d\n", *retval);
    printf("main thread get child thread id %lld\n", tid);
    return 0;
}
