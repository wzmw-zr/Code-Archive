/*************************************************************************
	> File Name: 4.progress.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月08日 星期三 21时30分32秒
 ************************************************************************/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;

int main(){

    int pid = fork();
    if (pid==0){
        printf("%d\n",count);
        count++;
        printf("%d\n",count);
        int pid2 = fork();
        if (pid2 == 0){
            char** argv = (char**) malloc(3*sizeof(char*));
            argv[0] = "echo";
            argv[1] = "Hello!";
            argv[2] = NULL;
            int pid3 = fork();
            printf("%d\n",count);
            count++;
            printf("%d\n",count);
            if (pid3 == 0){
                printf("%d\n",count);
                count++;
                printf("%d\n",count);
                execvp("echo", argv);
                printf("Count %d,",count);
                exit(0);
            } else {
                free(argv);
                wait(NULL);
                printf("%d\n",count);
                exit(0);
            }
        } else {
            wait(NULL);
            printf("%d\n",count);
            exit(0);
        }
    } else {
        wait(NULL);
        printf("%d\n",count);
        return 0;
    }    
}
