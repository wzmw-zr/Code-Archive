/*************************************************************************
	> File Name: 4.memory.map.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月07日 星期五 10时58分35秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<mqueue.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/mman.h>

int main() {
    char *sentence = (char *) mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    pid_t pid = fork();
    if (pid == -1) {
        printf("fork failed\n");
        return -1;
    }

    if (!pid) {
        scanf("%s", sentence);
        exit(0);
    } else {
        int status;
        if (wait(&status) == -1) {
            printf("wait failed\n");
            return -1;
        }
        if (status == -1) {
            printf("exit failed\n");
            return -1;
        }
        printf("%s\n", sentence);
        munmap(sentence, 1024);
    }
    return 0;
}
