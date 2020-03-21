/*************************************************************************
	> File Name: 8.more.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月20日 星期五 22时35分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<ncurses.h>

void more(char *filename) {
    printf("filename = %s", filename);
    fflush(stdout);
    sleep(3);
    printf("\r\033[k");
}

int main(int argc, char **argv) {
    initscr();
    printw("Hello world!\n");
    refresh();
    printw("hhhhh\n");
    refresh();
    echo();
    getch();
    sleep(3);
    endwin();
    /*while (--argc) {
        more(*(++argv));
    }*/
    return 0;
}
