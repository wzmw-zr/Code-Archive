/*************************************************************************
	l> File Name: 9.more.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月21日 星期六 22时52分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ioctl.h>

int h, w;

void GetWinSize() {
    struct winsize size;
    if (isatty(STDOUT_FILENO) == 0) {
        exit(1);
    }
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctl");
        exit(1);
    }
    h = size.ws_row, w = size.ws_col;
}

int get_cmd() {
    FILE *fp;
    if (!(fp = fopen("/dev/tty", "r"))) {
        perror("fopen");
        exit(1);
    }
    int c;
    while ((c = fgetc(fp)) != EOF) {
        switch (c) {
            case 'q' : return 0;
            case ' ' : return h;
            case '\n' : return 1;
        }
    }
    return -1;
}


void more(FILE *fp) {
    GetWinSize();
    int cnt = 0;
    char line[w + 10];
    memset(line, 0, sizeof(char) * w + 10);
    while (fgets(line, w, fp)) {
        fputs(line, stdout);
        cnt++;
        if (cnt == h) {
            int ret = get_cmd();
            if (ret == 0) return ;
            if (ret == -1) ret = get_cmd();
            cnt -= ret;
        }
    }
    while (get_cmd());
}

int main(int argc, char **argv) {
    if (argc == 1) {
        more(stdin);
    } else {
        while (--argc) {
            FILE *fp;
            if (!(fp = fopen(*(++argv), "r"))) perror("fopen");
            else more(fp);
        }
    }
    return 0;
}
