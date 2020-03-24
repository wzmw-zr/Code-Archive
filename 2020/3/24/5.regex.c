/*************************************************************************
	> File Name: 5.regex.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月24日 星期二 22时05分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdarg.h>
#include<unistd.h>
#include<fcntl.h>
#include<wait.h>
#include<regex.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    regex_t preg;
    int ret;
    char string1[100] = "test.c";
    char string2[100] = "test.cpp";
    if (regcomp(&preg, "*.cpp", REG_EXTENDED | REG_NEWLINE)) {
        perror("regcomp");
        exit(1);
    }
    if ((ret = regexec(&preg, string1, 0, NULL, 0))) {
        printf("match %s failed\n", string1);
    } else {
        printf("match %s successfully!\n", string1);
    }
    if ((ret = regexec(&preg, string2, 0, NULL, 0))) {
        printf("match %s failed\n", string2);
    } else {
        printf("match %s successfully!\n", string2);
    }
    return 0;
}
