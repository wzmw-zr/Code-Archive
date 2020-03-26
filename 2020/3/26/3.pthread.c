/*************************************************************************
	> File Name: 3.pthread.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月26日 星期四 22时32分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>

typedef struct Name {
    char name[100];
} Name;

void *show(void *name) {
    Name *tmp = (Name *) name;
    char *retval = (char *) malloc(sizeof(tmp->name));
    sprintf(retval, "world");
    pthread_exit((void *) retval);
}

int main(int argc, char **argv) {
    pthread_t tid;
    Name name;
    scanf("%s", name.name);
    if (pthread_create(&tid, NULL, show, (void *) &name)) {
        perror("pthread_create");
        exit(1);
    }
    void *str;
    if (pthread_join(tid, &str)) {
        perror("pthread_join");
        exit(1);
    }
    printf("%s\n", (char *) str);
    free(str);
    return 0;
}
