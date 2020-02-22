/*************************************************************************
	> File Name: 1.pthread.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月08日 星期六 08时45分04秒
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

void *get_id(void *arg) {
    pthread_t tid = pthread_self();
    printf("child pthread id = %lld\n", tid);
    return (void *) 0;
}

int main() {
    pthread_t tid;
    if (pthread_create(&tid, NULL, get_id, NULL)) {
        printf("create thread failed\n");
        return -1;
    }
    printf("main thread id is %lld\n", pthread_self());
    printf("main thread get child thread id %lld\n", tid);
    long *retval;
    if (pthread_join(tid, (void *)retval)) {
        printf("child thread exit failed\n");
        return -1;
    }
    printf("main thread get child thread exit value is %lld\n", *retval); 
    return 0;
}
