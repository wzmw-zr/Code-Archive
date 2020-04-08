/*************************************************************************
	> File Name: 6.popen.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月07日 星期二 23时27分26秒
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
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/mman.h>

int main() {
    char name[2048] = {0};
    FILE *fp = popen("ls", "w");
    //read(fp->_fileno, name, sizeof(name));
    scanf("%[^\n]s", name);
    fprintf(fp, "%s\n", name);
    printf("%s\n", name);
    pclose(fp);
    return 0;
}
