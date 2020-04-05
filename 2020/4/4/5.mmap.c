/*************************************************************************
	> File Name: 5.mmap.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月04日 星期六 23时36分48秒
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

char *mmap_addr;

int main() {
    FILE *fp = fopen("tmp_file", "r");
    int fd = fp->_fileno;
    int len = lseek(fd, 0, SEEK_END);
    mmap_addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mmap_addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    printf("%s\n", mmap_addr);
    munmap(mmap_addr, len);
    fclose(fp);
    return 0;
}
