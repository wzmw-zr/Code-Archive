/*************************************************************************
	> File Name: 2.thread.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月08日 星期六 09时05分30秒
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

void *getval(void *arg) {
    printf("child thread get arg %d\n", *((int *)arg));
    pthread_exit((void *) 0);
}

int main() {
    pthread_t tid;
    int arg;
    printf("arg = ");
    scanf("%d", &arg);
    if (pthread_create(&tid, NULL, getval, &arg)) {
        printf("cannot create child thread\n");
        return -1;
    }
    printf("main thread get child thread id %lld\n", tid);
    int *retval;
    if (pthread_join(tid, (void *) retval)) {
        printf("cannot get child thread exit value\n");
        return -1;
    }
    printf("main thread get child thread exit value %d\n", *retval);
    return 0;
}
