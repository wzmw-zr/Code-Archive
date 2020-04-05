/*************************************************************************
	> File Name: 5.client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月05日 星期日 19时24分34秒
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

typedef struct Shm {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int flag;
    char data[1024];
} Shm;

char pathname[100] = ".";
Shm *shmaddr;

int main() {
    key_t key;
    int shmid;
    if ((key = ftok(pathname, 101)) == -1) {
        perror("ftok");
        exit(1);
    }
    printf("key = %d\n", key);
    if ((shmid = shmget(key, sizeof(Shm), 0666)) == -1) {
        perror("shmget");
        exit(1);
    }
    if ((shmaddr = (Shm *) shmat(shmid, NULL, 0)) == (Shm *) (void *) -1) {
        perror("shmat");
        exit(1);
    }
    /*pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;
    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);
    pthread_mutexattr_setpshared(&m_attr, PTHREAD_PROCESS_SHARED);
    pthread_condattr_setpshared(&c_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&shmaddr->mutex, &m_attr);
    pthread_cond_init(&shmaddr->cond, &c_attr);
    */
    while (1) {
        pthread_mutex_lock(&shmaddr->mutex);
        while (shmaddr->flag) pthread_cond_wait(&shmaddr->cond, &shmaddr->mutex);
        shmaddr->flag = 1;
        printf("<client send>");
        scanf("%[^\n]s", shmaddr->data);
        getchar();
        //printf("%s\n", shmaddr->data);
        pthread_mutex_unlock(&shmaddr->mutex);
        pthread_cond_signal(&shmaddr->cond);
        sleep(3);
    }
    return 0;
}

