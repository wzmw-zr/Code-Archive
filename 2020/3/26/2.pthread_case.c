/*************************************************************************
	> File Name: 1.pthread_case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月26日 星期四 19时50分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>

typedef struct Msg {
    int age;
    char name[20];
    int retval;
} Msg;

void *print(void *arg) {
    Msg *tmp = (Msg *) arg;
    printf("name = %s, age = %d\n", tmp->name, tmp->age);
    tmp->retval = 3;
    pthread_exit((void *) &(tmp->retval));
}

int main(int argc, char **argv) {
    void *status;
    pthread_t tid;
    Msg msg;
    msg.age = 18;
    strcpy(msg.name, "zhaorui");
    pthread_create(&tid, NULL, print, (void *)&msg);
    pthread_join(tid, &status);
    printf("%d\n", *(int *)status);
    return 0;
}
