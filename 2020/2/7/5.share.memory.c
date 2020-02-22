/*************************************************************************
	> File Name: 5.share.memory.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月07日 星期五 14时44分05秒
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
    char name[20] = "/case";
    int shm_fd = shm_open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (shm_fd == -1) {
        printf("cannot make shared memory\n");
        return -1;
    }
    printf("shm_fd = %d\n", shm_fd);
    if (ftruncate(shm_fd, 1024) == -1) {
        printf("ftruncate failed\n");
        return -1;
    }
    pid_t pid = fork();
    if (pid == -1) {
        printf("fork failed\n");
        return -1;
    } 

    if (!pid) {
        char content[100] = {0};
        scanf("%s", content);
        if (write(shm_fd, content, strlen(content)) == -1) {
            printf("write error\n");
            return -1;
        }
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
        char result[100] = {0};
        lseek(shm_fd, 0, SEEK_SET);
        if (read(shm_fd, result, 100) == -1) {
            printf("read error\n");
            return -1;
        }
        printf("%s\n", result);
    }
    if (shm_unlink("/case") == -1) {
        printf("unlink error\n");
        return -1;
    }
    return 0;
}
