/*************************************************************************
	> File Name: 1.process.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月24日 星期二 18时55分57秒
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
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    printf("fork\n");
    for (int i = 1; i <= 1; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } 
        if (pid == 0) {
            printf("child\n");
            exit(0);
        }
        sleep(1);
        printf("parent\n");
    }
    return 0;
}
