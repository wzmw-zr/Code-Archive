/*************************************************************************
	> File Name: 5.select.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月09日 星期四 19时57分49秒
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
#include<sys/select.h>
#include<sys/time.h>

int main(void) {
    fd_set rfds;
    struct timeval tv;
    int retval;
    /* Watch stdin (fd 0) to see when it has input. */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    /* Wait up to five seconds. */
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don't rely on the value of tv now! */
    if (retval == -1)
        perror("select()");
    else if (retval) {
        char buff[1024] = {0};
        scanf("%[^\n]s", buff);
        printf("Data is available now.\n"); 
    }
    /* FD_ISSET(0, &rfds) will be true. */
    else
        printf("No data within five seconds.\n");
    exit(EXIT_SUCCESS);
}

