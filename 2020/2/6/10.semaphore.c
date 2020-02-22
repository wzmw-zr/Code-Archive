/*************************************************************************
	> File Name: 10.semaphore.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 18时54分27秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main() {
    sem_t *sem = sem_open("20200206", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, 0);
    int pid = fork();
    if (pid == 0) {
        //printf("first this is the child process\n");
        sem_post(sem);
        printf("second this is the child process\n");
    } else {
        //printf("first this is parent process\n");
        sem_wait(sem);
        printf("second this is parent process\n");
    }
    if (sem_close(sem) == -1) {
        printf("close failed\n");
        return -1;
    }
    if (sem_unlink("20200206") == -1) {
        printf("unlink failed\n");
        return -1;
    }
    return 0;
}
