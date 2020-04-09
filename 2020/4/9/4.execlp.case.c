/*************************************************************************
	> File Name: 4.execlp.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月09日 星期四 08时05分27秒
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


int main() {
    pid_t pid;
    char command[256] = {0};
    scanf("%[^\n]s", command);
    getchar();
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        int ind = 0;
        char **cmd = parse_cmd(command);
        while (cmd[ind]) printf("%s ", cmd[ind++]);
        execvp(cmd[0], cmd);
        exit(0);
    } else {
        wait(NULL);
    }
    return 0;
}
