/*************************************************************************
	> File Name: 1.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月01日 星期六 16时44分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<mqueue.h>

int main(int argc, char *argv[]) {
    const char name[90] = "20200201";
    mqd_t mq = mq_open(name, O_CREAT|O_EXCL, S_IRWXU, NULL);
    printf("%d\n", mq);
    if (!mq_close(mq)) printf("close successful");
    else printf("close failed!");
    return 0;
}
