/*************************************************************************
	> File Name: test1.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 19时31分35秒
 ************************************************************************/

#include<stdio.h>
#include<curses.h>
#define MAX_L 105
#define MAX_H 35

void draw_axis() {
    for (int i = 1; i <= MAX_L + 5; i++) {
        move(0, i);
        printw("-");
    }
    for (int i = 1; i <= MAX_H + 5; i++) {
        move(i, 0);
        printw("|");
    }
}

void draw_field() {
    for (int i = 1; i <= MAX_L; i++) {
        move(0, i);
        printw("-");
        move(MAX_H, i);
        printw("-");
    }
    for (int i = 1; i <= MAX_H; i++) {
        move(i, 0);
        printw("|");
        move(i, MAX_L);
        printw("|");
    }
}

void draw_help_area() {
    for (int i = 1; i <= 20; i++) {
        move(0, MAX_L + i + 3);
        printw("-");
        move(MAX_H, MAX_L + i + 3);
        printw("-");
    } 
    for (int i = 1; i <= MAX_H; i++) {
        move(i, MAX_L + 1 + 3);
        printw("|");
        move(i, MAX_L + 20 + 3);
        printw("|");
    }
}

void draw_ontime_area() {
    for (int i = 1; i <= MAX_L + 25; i++) {
        move(MAX_H + 3, i);
        printw("-");
        move(MAX_H + 10, i);
        printw("-");
    }

    for (int i = MAX_H + 3; i <= MAX_H + 10; i++) {
        move(i, 0);
        printw("|");
        move(i, MAX_L + 25);
        printw("|");
    }

}

void draw_door() {
    move(0, 14);
    printw("--");
    move(0, 22);
    printw("--");

    for (int i = 14; i <= 22; i++) {
        move(i, 0);
        printw("|");
        move(i, 2);
        printw("|");
    }
}

int main() {
    initscr();
    clear();
    draw_field();
    draw_help_area();
    draw_ontime_area();
    //draw_door();
    refresh();
    getchar();
    endwin();
    return 0;
}
