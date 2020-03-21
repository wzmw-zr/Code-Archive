/*************************************************************************
    > File Name: 5.more.c
    > Author:赵睿 
    > Mail: 1767153298@qq.com
    > Created Time: 2020年03月21日 星期六 19时30分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<termios.h>

#define PAGELINE 10
#define LENLINE 512

int get_cmd(FILE *fp) {
    printf("more:");
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == 'q') return 0;
        if (c == ' ') return PAGELINE;
        if (c == '\n') return 1;
    }
    return -1;
}

void do_more(FILE *fp) {     
    char line[LENLINE] = {0};
    FILE *cmd = fopen("/dev/tty", "r");
    int num_line = 0, reply, get_cmd(FILE *);
    while (fgets(line, LENLINE, fp)) {
        if (num_line == PAGELINE) {
            reply = get_cmd(cmd);
            if (reply == 0) break;
            num_line -= reply;
        }
        if (fputs(line, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
        num_line++;
    }
    if (fclose(fp)) perror("fclose"); 
}

int main(int argc, char **argv) {
    FILE *fp;
    if (argc == 1) {
        do_more(stdin);
    }
    else {
        while (--argc) {
            if ((fp = fopen(*(++argv), "r"))) {
                do_more(fp);
            }
        }
    }
    return 0;
}
