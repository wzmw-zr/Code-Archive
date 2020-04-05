/*************************************************************************
	> File Name: 4.client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月04日 星期六 20时11分04秒
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


int main() {
    key_t key = ftok(".", 100);
    int shmid = shmget(key, sizeof(Data), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | IPC_CREAT);
    //int shmid = shmget(key, 4096, O_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        perror("shmat");
        exit(1);
    }
    Data data;
    while (1) {
        printf("Client send : ");
        scanf("%[^\n]s", data.data);
        data.flag = 1;
        memcpy(shmaddr, &data, sizeof(Data));
        memset(&data, 0, sizeof(Data));
        memcpy(shmaddr, &data, sizeof(Data));
        getchar();
    }
    shmdt(shmaddr);
    return 0;
}

