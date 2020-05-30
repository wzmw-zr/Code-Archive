/*************************************************************************
	> File Name: 2.play_again.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月28日 星期四 20时00分21秒
 ************************************************************************/

#include <head.h>
#include <termios.h>
#include <ctype.h>

#define Q "Do you want another try?"
#define TIMEOUT 5

int get_response();
void tty_mode(int how);
void set_cr_noecho_mode();
void set_nonblock_mode();
int get_ok_char();

int main() {
    int response;
    tty_mode(0);
    set_cr_noecho_mode();
    response = get_response();
    tty_mode(1);
    return response;
}

int get_ok_char() {
    int c;
    while ((c = getchar()) != EOF && strchr("yYnN", c) == NULL);
    return c;
}

int get_response() {
a1: printf(Q);
    printf("(y/n)? : ");
    fflush(stdout);
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    fd_set set;
    FD_ZERO(&set);
    FD_SET(0, &set);

    int ret = select(1, &set, NULL, NULL, &tv);
    if (ret == 1) {
        if (FD_ISSET(0, &set)) {
            while (1) {
                int input = tolower(getchar());
                switch (input) {
                    case 'y': return 1; 
                    case 'n': return 0;
                    default : printf("\n"); goto a1;
                }
            }
        }
    }
    return 2;
}

void set_nonblock_mode() {
    int termflags;
    termflags = fcntl(0, F_GETFL);
    termflags |= O_NONBLOCK;
    fcntl(0, F_SETFL, termflags);
}

void set_cr_noecho_mode() {
    struct termios ttystate;
    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ECHO;
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &ttystate);
}

void tty_mode(int how) { 
    // how = 1, recover; how = 0, store;
    static struct termios original_mode;
    if (how == 0) {
        tcgetattr(0, &original_mode);
    } else {
        tcsetattr(0, TCSANOW, &original_mode);
    }
}
