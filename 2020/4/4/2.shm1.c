/*************************************************************************
	> File Name: 2.shm1.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月04日 星期六 19时09分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<signal.h>


char *share_memory;

void print(int sig) {
    printf("<parent> : %s\n", share_memory);
}

int main() {
    pid_t pid;
    int shmid;
    key_t key = ftok("lock", 198);
    if ((shmid = shmget(key, 4096, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((share_memory = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        exit(1);
    }
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        while (1) {
            printf("<child> :");
            scanf("%[^\n]s", share_memory);
            getchar();
            kill(getppid(), SIGUSR2);
            exit(1);
        }
    } else {
        while (1) {
            signal( SIGUSR2, print);
            wait(NULL);
        }
    }
    shmdt(share_memory);
    return 0;
}
