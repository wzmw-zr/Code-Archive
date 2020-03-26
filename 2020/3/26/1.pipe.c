/*************************************************************************
	> File Name: 1.pipe.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月26日 星期四 08时20分27秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    int filedes[2];
    if (pipe(filedes) == -1) {
        perror("pipe");
        exit(1);
    }
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        printf("child fd[0] = %d, fd[1] = %d\n", filedes[0], filedes[1]);
        char name[100] = "This is child, communicate with father\n";
        if (write(filedes[1], name, strlen(name)) == -1) {
            perror("write");
            exit(1);
        }
        exit(0);
    } else {
        int status;
        if (wait(&status) == -1) {
            perror("wait");
            exit(1);
        } 
        printf("father fd[0] = %d, fd[1] = %d\n", filedes[0], filedes[1]);
        char name[100];
        if (read(filedes[0], name, sizeof(name)) == -1) {
            perror("read");
            exit(1);
        }
        printf("child tell me : %s", name);
    }
    return 0;
}
