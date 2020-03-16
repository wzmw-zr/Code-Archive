/*************************************************************************
	> File Name: 1.ls.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月16日 星期一 15时29分20秒
 ************************************************************************/

#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ioctl.h>

int GetTerminalWidth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int main(int argc, char **argv) {
    printf("Termianl width = %d\n", GetTerminalWidth());
    printf("argc = %d\n", argc);
    DIR *dirp = opendir(".");
    printf("dirp = NULL ? %s\n", dirp ? "No" : "Yes");
    struct dirent *dir_entry;
    while ((dir_entry = readdir(dirp)) != NULL) {
        printf("%s ", dir_entry->d_name);
    }
    printf("\n");
    closedir(dirp);
    return 0;
}
