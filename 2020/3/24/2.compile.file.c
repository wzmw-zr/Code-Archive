/*************************************************************************
	> File Name: 2.compile.file.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月24日 星期二 20时38分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<wait.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s xxx.c/xxx.cpp\n", argv[0]);
        exit(1);
    }
    if (access(argv[1], F_OK | R_OK | W_OK) == -1) {
        pid_t pid;
        if ((pid = fork()) == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            if (execl("/usr/bin/touch", "touch", argv[1], NULL) == -1) {
                perror("execl");
                exit(1);
            }
        } else {
            int status;
            if (wait(&status) == -1) {
                perror("wait");
                exit(1);
            }
            return 1;
        }
    } else {
        pid_t pid;
        if ((pid = fork()) == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            if (execl("/usr/bin/gcc", "gcc", argv[1], "-o", "case", NULL) == -1) {
                perror("execl");
                exit(1);
            }
        } else {
            int status;
            if (wait(&status) == -1) {
                perror("wait");
                exit(1);
            }
            if ((pid = fork()) == -1) {
                perror("fork");
                exit(1);
            } else if (pid == 0) {
                if (execl("./case", "case", NULL) == -1) {
                    perror("execl");
                    exit(1);
                }
            } else {
                printf("finally\n");
            }
        }
    }
    return 0;
}
