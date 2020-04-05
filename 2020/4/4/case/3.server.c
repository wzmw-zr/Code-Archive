/*************************************************************************
	> File Name: 3.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月04日 星期六 19时58分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>

char *shmaddr;

typedef struct Data {
    int flag;
    char data[4092];
} Data;

void print(int sig) {
    printf("<server> : %s\n", shmaddr);
}

int main() {
    key_t key = ftok(".", 100);
    int shmid = shmget(key, sizeof(Data), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | IPC_CREAT);
    //int shmid = shmget(key , 4096, O_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        perror("shmat");
        exit(1);
    }
    memset(shmaddr, 0, sizeof(Data));
    Data data;
    while (1) {
        memcpy(&data, shmaddr, sizeof(Data));
        if (!data.flag) continue;
        printf("<server get>:%s\n", data.data);
    }
    shmdt(shmaddr);
    return 0;
}
