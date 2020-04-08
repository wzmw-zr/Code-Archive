/*************************************************************************
	> File Name: 7.popen.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月07日 星期二 23时35分34秒
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

FILE *my_popen(char *command, char *type) {
    FILE *fp = (FILE *) calloc(sizeof(FILE), 0);
    int pipefd[2];
    pid_t pid;
    pipe(pipefd);
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } 
    if (pid == 0) {
        if (type[0] == 'r') {
            dup2(pipefd[1], 1);
            execlp(command, command, NULL);
        } else if (type[0] == 'w') {
            dup2(1, pipefd[0]);
        }
        exit(0);
    } else {
        if (type[0] == 'r') {
            dup2(fp->_fileno, pipefd[0]);
        } else if (type[0] == 'w'){
            dup2(pipefd[1], fp->_fileno);
            char tmp[1024] = {0};
            scanf("%[^\n]s", tmp);
            getchar();
        }
        wait(NULL);
    }
    return fp;
}

int main() {
    FILE *fp = my_popen("ls", "r");
    return 0;
}
