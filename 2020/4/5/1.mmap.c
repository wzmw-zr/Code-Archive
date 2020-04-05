/*************************************************************************
	> File Name: 1.mmap.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月05日 星期日 08时35分48秒
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

int main() {
    int fd = open("case.txt", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, 100);
    char *word  = NULL;
    if ((word = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == (void *) -1) {
        perror("mmap");
        exit(1);
    }
    scanf("%[^\n]s", word);
    getchar();
    close(fd);
    return 0;
}
