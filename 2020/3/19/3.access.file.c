/*************************************************************************
	> File Name: 3.access.file.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月19日 星期四 23时22分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char **argv) {
    while (--argc) {
        if (access(*(++argv), R_OK)) {
            fprintf(stderr, "%s doesn't exist!\n", *argv);
        } else {
            printf("%s truly exist!\n", *argv);
        }
    }
    return 0;
}
