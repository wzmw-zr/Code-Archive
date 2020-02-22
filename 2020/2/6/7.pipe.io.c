/*************************************************************************
	> File Name: 7.pipe.io.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 15时24分43秒
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
        printf("cannot open pipe\n");
        return -1;
    }
    printf("filedes[0] = %d, filedes[1] = %d\n", filedes[0], filedes[1]);
    int pid = fork();
    if (!pid) {
        close(filedes[0]);
        char sentence[100] = "hello parent id!\n";
        write(filedes[1], sentence, strlen(sentence));
        exit(0);
    } else {
        close(filedes[1]);
        int status;
        if (wait(&status) == -1) {
            printf("wait failed\n");
            return -1;
        }
        if (status == -1) {
            printf("child process exit failed\n");
            return -1;
        }
        char output[100] = {0};
        if (read(filedes[0], output, 20) == -1) {
            printf("pipe read error!\n");
            return -1;
        }
        printf("len = %d\n", strlen(output));
        printf("%s\n", output);
    }
    return 0;
}
