/*************************************************************************
	> File Name: 7.multi.process.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月23日 星期一 22时24分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    int fd;
    if ((fd = open("7.multi.process.c", O_RDONLY)) == -1) {
        perror("7.multi.process.c");
        exit(1);
    }
    int pid = fork();
    if (pid == 0) {
        printf("child fd = %d\n", fd);
        printf("child pid = %d, ppid = %d\n", getpid(), getppid());
    } else {
        printf("father fd = %d\n", fd);
        printf("father pid = %d, ppid = %d\n", getpid(), getppid());
        int status;
        if (wait(&status) == -1) {
            perror("wait");
            exit(1);
        } 
        printf("if child process exit ? %s\n", WIFEXITED(status) ? "Yes" : "No");
    }
    return 0;
}
