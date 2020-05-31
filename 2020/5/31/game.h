/*************************************************************************
	> File Name: game.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月31日 星期日 16时25分46秒
 ************************************************************************/

#ifndef _GAME_H
#define _GAME_H
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
#include<curses.h>
#define X 70
#define Y 30

struct point {
    int x, y;
};

struct point Bpoint;
struct point Opoint;
int cx = (X - 2) / 2 + 1;
int cy = (Y - 2) / 2 + 1;

void gotoxy(int x, int y) {
    move(y, x);
}

void gotoxy_putc(int x, int y, char c) {
    mvaddch(y, x, c);
    move(LINES - 1, 1);
    refresh();
}

void gotoxy_puts(int x, int y, char *s) {
    move(y, x); 
}

void initfield(int x, int y) {
    mvaddch(0,, 0, '0');
    //mvaddch(0, X, 'X');
    gotoxy_putc(X + 2, 0, 'X');
    //mvaddch(Y, 0, 'Y');
    gotoxy_putc(0, Y + 2, 'Y');
    attron(COLOR_PAIR(1));
    for (int i = 1; i <= x; i++) {
        gotoxy_putc(i, 1, '-'); 
        gotoxy_putc(i, y, '-');
    }
    for (int i = 1; i <= y; i++) {
        gotoxy_putc(1, i, '|');
        gotoxy_putc(x, i, '|');
    }
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    gotoxy_puts(2, Y + 3, "Message:");
    gotoxy_puts(X + 3, 2, "Message:");
    attroff(COLOR_PAIR(2));
}

void initgame() {
    if (!has_colors() || start_color == ERR) {
        endwin();
        fprintf(stderr, "Terminal doesn't support color!\n");
        exit(1);
    }
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_CYAN);
    initfield(X, Y);

    Bpoint.x = cx - 3;
    Bpoint.y = Y - 3;
    attron(COLOR_PAIR());
    for (int i = 0; i < 8; i++) {
        gotoxy_putc(Bpoint.x + i, Bpoint.y, ' ');
        gotoxy_putc(Bpoint.x + i, Bpoint.y + 1, ' ');
    }
    attroff(COLOR_PAIR(3));
    refresh();
}
#endif
