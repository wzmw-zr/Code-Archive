/*************************************************************************
	> File Name: 4.ipc.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月07日 星期二 20时18分43秒
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
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/mman.h>

int main() {
    pid_t pid;
    int pipefd[2];
    pipe(pipefd);
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        close(pipefd[0]);
        char sentence[512];
        while (1) {
            printf("<child process>:");
            scanf("%[^\n]s", sentence);
            getchar();
            write(pipefd[1], sentence, strlen(sentence));
        }
    } else {
        close(pipefd[1]);
        char sentence[512];
        while (1) {
            printf("<parent process read>:");
            read(pipefd[0], sentence, sizeof(sentence));
            printf("%s\n", sentence);
            memset(sentence, 0, sizeof(sentence));
        }
    }
    return 0;
}
