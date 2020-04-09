/*************************************************************************
	> File Name: 2.popen.pclose.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月09日 星期四 07时44分02秒
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

char **parse_cmd(char *command) {
    int ind = 0;
    char **cmd = (char **) calloc(sizeof(char *), strlen(command));
    char *token = strtok(command, " ");
    while (token) {
        cmd[ind++] = token; 
        token = strtok(NULL, " ");
    }
    return cmd;
}

FILE *my_popen(char *command, char *mode) {
    pid_t pid;
    FILE *ret = NULL;
    int pipefd[2];
    pipe(pipefd);
    if (mode[0] == 'r') {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            close(pipefd[0]);
            dup2(pipefd[1], 1);
            char **cmd = parse_cmd(command);
            execvp(cmd[0], cmd);
            exit(0);
        } else {
            close(pipefd[1]);
            ret = fdopen(pipefd[0], "r");
            wait(NULL);
            return ret;
        }
    }
    if (mode[0] == 'w') {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            close(pipefd[1]);
            char data[1024] = {0};
            dup2(pipefd[0], 0);
            char **cmd = parse_cmd(command);
            execvp(cmd[0], cmd);
            exit(0);
        } else {
            close(pipefd[0]);
            ret = fdopen(pipefd[1], "w");
            return ret;
        }
    }
    return NULL;
}

void my_pclose(FILE *fp) {
    close(fp->_fileno);
    free(fp);
}

int main() {
    char command[256] = {0};
    char mode[10] = {0};
    FILE *fp = NULL;
    printf("input command:");
    scanf("%[^\n]s", command);
    getchar();
    printf("input mode:");
    scanf("%[^\n]s", mode);
    getchar();
    if ((fp = my_popen(command, mode)) == NULL) {
        perror("my_popen");
        exit(1);
    }
    if (mode[0] == 'r') {
        char *data = (char *) calloc(sizeof(char), 1024);
        size_t num = 1024;
        while (getline(&data, &num, fp) != -1) {
            printf("%s", data);
            memset(data, 0, 1024);
            num = 1024;
        }
    } else {
        char data[1024] = {0};
        printf("input data:");
        scanf("%[^\n]s", data);
        getchar();
        if (fputs(data, fp) < 0) {
            perror("fputs");
            exit(1);
        }
        fflush(fp);
    }
    wait(NULL);
    my_pclose(fp);
    return 0;
}
