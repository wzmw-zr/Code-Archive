/*************************************************************************
	> File Name: 1.popen.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月09日 星期四 07时34分31秒
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
    char command[256] = {0};
    FILE *fp = NULL;
    printf("input command:");
    scanf("%[^\n]s", command);
    getchar();
    if ((fp = popen(command, "w")) == NULL) {
        perror("popen");
        exit(1);
    }
    char *line = (char *) calloc(sizeof(char), 256);
    size_t num = 256;
    /*while (getline(&line, &num, fp) != -1) {
        printf("%s", line);
        memset(line, 0, sizeof(char) * 256);
        num = 256;
    } */
    scanf("%[^\n]s", line);
    getchar();
    fputs(line, fp);
    return 0;
}
