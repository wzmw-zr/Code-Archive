/*************************************************************************
	> File Name: 2.shm.add.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月05日 星期日 14时49分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<semaphore.h>

char pathname[100] = ".";

typedef struct Data {
    int num, sum;
} Data;

Data data;

char *shmaddr;

void getvalue(int *num, int *sum) {
    Data tmp;
    memcpy(&tmp, shmaddr, sizeof(Data));
    *num = tmp.num;
    *sum = tmp.sum;
}

void setvalue(int num, int sum, int top) {
    Data tmp;
    if (num > top) {
        printf("process %lu, num = %d, sum = %d\n", getpid(), num, sum);
        exit(1);
    }
    printf("process %lu, num = %d, sum = %d\n", getpid(), num, sum);
    tmp.num = num;
    tmp.sum = sum;
    memcpy(shmaddr, &tmp, sizeof(Data));
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s num process_number\n", argv[0]);
        exit(1);
    }
    int num = atoi(argv[1]);
    int cnt = atoi(argv[2]);
    printf("num = %d, cnt = %d\n", num, cnt);
    key_t key;
    int shmid;
    if ((key = ftok(pathname, 100)) == -1) {
        perror("ftok");
        exit(1);
    }
    if ((shmid = shmget(key, sizeof(Data), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shmaddr = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }
    memcpy(shmaddr, &data, sizeof(Data));
    sem_t *semaddr = sem_open("2.shm.add.c", O_CREAT | O_RDWR, 1);
    pid_t pid;
    for (int i = 1; i <= cnt; i++) {
        printf("i = %d\n", i);
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        } 
        if (pid == 0) break;
    }
    if (pid == 0) {
        while (1) {
            printf("process %lu\n", getpid());
            sem_wait(semaddr);
            int number, sum;
            getvalue(&number, &sum);
            printf("process %lu, num = %d, sum = %d\n", getpid(), number, sum);
            sum += number;
            number++;
            setvalue(number, sum, num);
            sem_post(semaddr);
        }
    }
    while (cnt) {
        wait(NULL);
        cnt--;
    }
    return 0;
}
