/*************************************************************************
	> File Name: 8.pipe.io.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 16时35分20秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>


int main() {
    int filedes[2] = {0};
    if (pipe(filedes) == -1) {
        printf("open pipe failed!\n");
        return -1;
    }
    int pid = fork();
    if (!pid) {
        if (close(filedes[0]) == -1) {
            printf("cannot close filedes[0]\n");
            return -1;
        }
        char sentence[100] = "hello world";
        if (write(filedes[1], sentence, strlen(sentence)) == -1) {
            printf("write to pipe error!\n");
            return -1;
        }
        if (close(filedes[1]) == -1) {
            printf("close filedes[1] error\n");
            return -1;
        }
        exit(0);
    } else {
        if (close(filedes[1]) == -1) {
            printf("cannot close filedes[1]\n");
            return -1;
        }
        int status;
        if (wait(&status) == -1) {
            printf("child process exit error\n");
            return -1;
        }
        if (status == -1) {
            printf("child process error!\n");
            return -1;
        }
        char result[100] = {0};
        if (read(filedes[0], result, 15) == -1) {
            printf("read from pipe error\n");
            return -1;
        }
        printf("%s\n", result);
        if (close(filedes[0]) == -1) {
            printf("close filedes[0] error\n");
            return -1;
        }
    }
    return 0;
}
