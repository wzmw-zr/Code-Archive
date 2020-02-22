/*************************************************************************
	> File Name: 3.message.queue.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月07日 星期五 09时48分19秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<mqueue.h>

int main() {
    char name[20] = "/hello";
    mqd_t mqdes = mq_open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, NULL);
    int pid = fork();
    if (pid == -1) {
        printf("cannot fork!\n");
        return -1;
    }

    if (!pid) {
        char result[8200] = {0};
        size_t length = 8200;
        unsigned int *msg_prio = (unsigned int *) calloc(1, sizeof(unsigned int));
        ssize_t res_len = mq_receive(mqdes, result, length, msg_prio);
        printf("res_len = %d\n, result = %s, msg_prio = %d\n", res_len, result, *msg_prio);
        exit(0);
    } else {
        char content[8200] = {0};
        printf("content = ");
        scanf("%s", content);
        int len = strlen(content);
        unsigned int prio = 1;
        if (mq_send(mqdes, content, len, prio) == -1) {
            printf("send failed\n");
            return -1;
        }
        char contents[8200] = {0};
        printf("contents = ");
        scanf("%s", contents);
        int len2 = strlen(contents);
        unsigned int prio2 = 2;
        if (mq_send(mqdes, contents, len2, prio2) == -1) {
            printf("send failed\n");
            return -1;
        }
        int status;
        if (wait(&status) == -1) {
            printf("wait failed\n");
            return -1;
        }
        if (status == -1) {
            printf("exit failed\n");
            return -1;
        }
    }
    return 0;
}
