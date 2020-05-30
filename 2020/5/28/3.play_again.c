/*************************************************************************
	> File Name: 2.play_again.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月28日 星期四 20时00分21秒
 ************************************************************************/

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define Q "Do you want another try?"

int get_response();
void set_cr_mode();
void tty_mode(int how);

int main() {
    int response;
    tty_mode(0);
    set_cr_mode();
    response = get_response();
    tty_mode(1);
    return response;
}

int get_response() {
    printf(Q);
    printf("(y/n)? : ");
    switch (getchar()) {
        case 'y' : 
        case 'Y' : return 1;
        case 'n' : 
        case 'N' : return 0;
        default : return -1;
    }
    return -1;
}

void set_cr_mode() {
    struct termios ttystate;
    tcgetattr(0, &ttystate);
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
