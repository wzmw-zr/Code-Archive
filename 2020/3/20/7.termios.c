/*************************************************************************
	> File Name: 7.termios.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月20日 星期五 20时27分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<termios.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv) {
    int ttyfd = open("/dev/tty", O_RDWR);
    if (ttyfd == -1) {
        perror("open");
        exit(1);
    }
    struct termios tp, save;
    if (tcgetattr(ttyfd, &tp) == -1) {
        perror("tcgetattr");
        exit(1);
    }
    printf("tcgetattr successful!\n");
    save = tp;
    tp.c_lflag &= ~(ICANON | ECHO);
    tp.c_lflag |= ISIG;
    tp.c_iflag &= ~ICRNL;
    tp.c_cc[VMIN] = 1;
    tp.c_cc[VTIME] = 0;
    if (tcsetattr(ttyfd, TCSAFLUSH, &tp) == -1) {
        perror("tcsetattr");
        exit(1);
    }
    printf("first change successful!\n");
    char c;
    int flag = 0;
    while (~scanf("%c", &c)) {
        switch (c) {
            case 'q': flag = 1; break;
            default : printf("character is %c\n", c); break;
        }
        if (flag) break;
    }
    if (tcsetattr(ttyfd, TCSAFLUSH, &save) == -1) {
        perror("tcsetattr");
        exit(1);
    }
    printf("second change successful!\n");
    return 0;
}
