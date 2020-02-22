/*************************************************************************
	> File Name: 1.message.queue.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月07日 星期五 08时30分16秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<mqueue.h>
#include<sys/stat.h>

int main() {
    char *name = (char *) calloc(20, sizeof(char));
    scanf("%s", name);
    mqd_t mqdes = mq_open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, NULL);
    struct mq_attr *attr = (struct mq_attr *) calloc (1, sizeof(struct mq_attr));
    if (mq_getattr(mqdes, attr) == -1) {
        printf("cannot get the attributes!\n");
        return -1;
    }
    printf("mq_falgs = %lld, mq_maxmsg = %lld, mq_msgsize = %lld, mq_curmsgs = %lld\n", attr->mq_flags, attr->mq_maxmsg, attr->mq_msgsize, attr->mq_curmsgs);
    if (mq_close(mqdes) == -1) {
        printf("cannot close message queue!\n");
        return -1;
    }
    return 0;
}
