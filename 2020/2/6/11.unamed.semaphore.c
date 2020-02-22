/*************************************************************************
	> File Name: 11.unamed.semaphore.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 19时12分57秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<semaphore.h>

int main() {
    sem_t sem;
    if (sem_init(&sem, 1, 0) == -1) {
        printf("unamed semaphore failed\n");
        return -1;
    }
    int pid = fork();
    if (pid == -1) {
        printf("fork failed\n");
        return -1;
    }

    if (!pid) {
        sem_post(&sem);
        printf("this is child process\n");
        exit(0);
    } else {
        sem_wait(&sem);
        printf("this is parent process\n");
        int status;
        if (wait(&status) == -1) {
            printf("wait failed\n");
            return -1;
        }
        if (status == -1) {
            printf("exit failed\n");
            return -1;
        }
    }
    if (sem_destroy(&sem) == -1) {
        printf("semaphore destroy failed\n");
        return -1;
    }
    printf("semaphore destroy successfully!\n");
    printf("pid = %d\n", getpid());
    return 0;
}
