/*************************************************************************
	> File Name: 5.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月07日 星期二 21时05分57秒
 ************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>



int main() {
    pid_t pid;
    FILE *fp, *fp1;
    int pipefd[2];
    pipe(pipefd);
    char buff[1024] = {0};
    if ((pid = fork()) < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        fp = fdopen(pipefd[1], "w");
        while (1) {
            printf("child : ");
            scanf("%[^\n]s", buff);
            //strcpy(buff, "okfine");
            //buff[strlen(buff)] = '\n';
            getchar();
            //printf("%s\n", fp->_IO_write_base);
            //write(fp->_fileno, buff, sizeof(buff));
            //printf("%s\n", fp->_IO_write_base);
            fprintf(fp, "%s", buff);
            printf("%s\n", fp->_IO_write_base);
            fflush(fp);
            //printf("%s\n", fp->_IO_write_base);
            memset(buff, 0, sizeof(buff));
        }
    } else {
        fp1 = fdopen(pipefd[0], "r");
        while (1) {
            printf("this is parent!\n");
            read(fp1->_fileno, buff, sizeof(buff));
            /*if (fscanf(fp1, "%s", buff) == EOF) {
                perror("fscanf");
                exit(1);
            }
            */
            //fscanf(fp1, "%s", buff);
            printf("server : %s\n", buff);
            memset(buff, 0, sizeof(buff));
        }
    }
    return 0;
}
