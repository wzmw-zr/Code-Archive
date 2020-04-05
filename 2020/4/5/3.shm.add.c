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
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<signal.h>

typedef struct Shm {
    int now;
    int sum;
    pthread_mutex_t mutex;
} Shm;

Shm *share_memory;

void do_add(int max, int x) {
    while (1) {
        pthread_mutex_lock(&share_memory->mutex);
        if (share_memory->now > max) { 
            pthread_mutex_unlock(&share_memory->mutex);
            break;
        }
        printf("<%d> : %d %d\n", x, share_memory->now, share_memory->sum);
        share_memory->sum += share_memory->now;
        (share_memory->now)++;
        pthread_mutex_unlock(&share_memory->mutex);
    }
    printf("<%d>: sum = %d\n", x, share_memory->sum);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s max ins\n", argv[0]);
        exit(1);
    }
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    int shmid;
    key_t key = ftok("lock", 198);
    if ((shmid = shmget(key, sizeof(Shm), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((share_memory = (Shm *) shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat");
        exit(1);
    }
    memset(share_memory, 0, sizeof(Shm));
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&(share_memory->mutex), &attr); 
    int x;
    pid_t pid;
    for (int i = 1; i <= ins; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            x = i;
            break;
        }
    }
    if (pid == 0) {
        do_add(max, x);
        exit(0);
    }
    while (ins) {
        wait(NULL);
        ins--;
    }
    printf("Ans: %d\n", share_memory->sum);
    shmdt(share_memory);
    return 0;
}
