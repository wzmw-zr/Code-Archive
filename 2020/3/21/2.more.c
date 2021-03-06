/*************************************************************************
	> File Name: 1.more.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月21日 星期六 07时50分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<ncurses.h>
#include<time.h>
#define PRESS_ENTER 1
#define PRESS_SPACE 10
#define DEFAULT_LINE 10

typedef struct FileContent {
    char **LineContent;
    int total_lines, cur_line;
} FileContent;

FileContent *InitFC(int line) {
    FileContent *fc = (FileContent *)calloc(sizeof(FileContent), 1);
    fc->total_lines = line;
    fc->cur_line = 0;
    fc->LineContent = (char **) calloc(sizeof(char *), line + 5);
    return fc;
}

int GetLines(char *filename) {
    FILE *fp = fopen(filename, "r");
    int lines = 0;
    while (!feof(fp)) {
        if (fgetc(fp) == '\n') lines++;
    }
    return lines;
}

void show(int number, FileContent *fc, FILE *fp, WINDOW *win, int h, int w) {
    char *LineContent = NULL;
    size_t LineChar = 0;
    for (int i = 1; i <= number && getline(&LineContent, &LineChar, fp) != -1; i++) {
        wprintw(win, "%s", LineContent);
        prefresh(win, 0, 0, 0, 0, h - 1, w);
        fc->LineContent[++(fc->cur_line)] = LineContent;
        LineContent = NULL;
        LineChar = 0;
    }
}

void more(char *filename) {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    int h, w;
    getmaxyx(stdscr, h, w);
    WINDOW *text;
    text = newwin(h - 1, w, 0, 0);
    WINDOW *input = newwin(1, w, h - 1, 0); 
    scrollok(text, TRUE);
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen");
        return ;
    }
    int lines = GetLines(filename);
    FileContent *fc = InitFC(lines);
    char *LineContent = NULL;
    size_t LineChar = 0;
    for (int i = 0; i < DEFAULT_LINE && getline(&LineContent, &LineChar, fp) != -1; i++) {
        //wprintw(text,"%s", LineContent);
        waddstr(text, LineContent);
        wrefresh(text); 
        fc->LineContent[++(fc->cur_line)] = LineContent;
        LineContent = NULL;
        LineChar = 0;
    }
    int c, flag = 0;
    while (c = wgetch(text)) {
        switch (c) {
            case 'q': flag = 1; break;
            case ' ': show(PRESS_SPACE, fc, fp, text, h, w); break;
            case '\n': show(PRESS_ENTER, fc, fp, text, h, w); break;
        }
        if (flag) break;
    }
    endwin();
}

int main(int argc, char **argv) {
    if (argc == 1) exit(1);
    more(*(++argv));
    return 0;
}
