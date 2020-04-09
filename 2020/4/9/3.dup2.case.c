/*************************************************************************
	> File Name: 3.dup2.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月09日 星期四 07时56分18秒
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
    char data[1024];
    size_t num = sizeof(data);
    int fd = open("./1.popen.case.c", O_RDWR | O_APPEND);
    int tmp_fd = open("./case", O_RDWR | O_CREAT, 0666);
    dup2(tmp_fd, 1);
    while (read(fd, data, num) > 0) {
        write(1, data, num); 
    }
    return 0;
}
