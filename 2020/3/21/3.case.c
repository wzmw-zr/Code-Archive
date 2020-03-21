/*************************************************************************
	> File Name: 3.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月21日 星期六 17时29分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv) {
    char file_path[100] = "/bin";
    char *real_path = realpath(file_path, NULL);
    struct stat s;
    if (lstat(file_path, &s) == -1) {
        perror("lstat");
        exit(1);
    }
    printf("is symlink ? %s\n", S_ISLNK(s.st_mode) ? "Yes" : "No");
    if (!real_path) {
        perror("realpath");
        exit(1);
    }
    printf("real_path = %s\n", real_path);
    free(real_path);
    return 0;
}
