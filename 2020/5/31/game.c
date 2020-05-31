/*************************************************************************
	> File Name: game.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月31日 星期日 16时25分14秒
 ************************************************************************/

#include "game.h"

void initgame();
void drawgame();

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    initgame();

    signal(14, drawgame);

    struct itimerval itimer;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = 100000;
    itimer.it_value.tv_sec = 0;
    itimer.it_value.tv_usec = 1000;

    setitimer(ITIMER_REAL, &itimer, NULL);

    while (1) {
        int c = getch();
        switch (c) {
            case KEY_LEFT:

            case KEY_RIGHT:

            default: break;
        }
    }
    
    getch();
    endwin();
    return 0;
}
