/*************************************************************************
	> File Name: 2.message.queue.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月07日 星期五 09时08分55秒
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
    if (mqdes == -1) {
        printf("cannot open or create message queue\n");
        return -1;
    }
    struct mq_attr *new_attr = (struct mq_attr *) calloc(1, sizeof(struct mq_attr));
    struct mq_attr *old_attr = (struct mq_attr *) calloc(1, sizeof(struct mq_attr));
    new_attr->mq_flags = O_NONBLOCK;
    new_attr->mq_maxmsg = 20;
    new_attr->mq_msgsize = 16384;
    if (mq_getattr(mqdes, old_attr) == -1) {
        printf("cannot get attributes\n");
        return -1;
    }
    printf("old_attr->mq_flags = %d, old_attr->mq_maxmsg = %d, old_attr->mq_msgsize = %d, old_attr->curmsgs = %d\n", old_attr->mq_flags, old_attr->mq_maxmsg, old_attr->mq_msgsize, old_attr->mq_curmsgs);
    if (mq_setattr(mqdes, new_attr, old_attr) == -1) {
        printf("change attributes failed!\n");
        return -1;
    }
    if (mq_getattr(mqdes, old_attr) == -1) {
        printf("cannot get attributes\n");
        return -1;
    }
    printf("old_attr->mq_flags = %d, old_attr->mq_maxmsg = %d, old_attr->mq_msgsize = %d, old_attr->curmsgs = %d\n", old_attr->mq_flags, old_attr->mq_maxmsg, old_attr->mq_msgsize, old_attr->mq_curmsgs);
    if (mq_close(mqdes) == -1) {
        printf("cannot close message queue\n");
        return -1;
    }
    return 0;
}
