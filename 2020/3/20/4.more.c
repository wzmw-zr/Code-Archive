/*************************************************************************
	> File Name: 4.more.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月20日 星期五 15时34分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define ENTER_LINE 1
#define SPACE_LINE 10

typedef struct FileContent {
    char **lines;
    int readlines, cur_line;
} FileContent;

FileContent *NewFileContent(int lines) {
    FileContent *fc = (FileContent *) calloc(sizeof(FileContent), 1);
    fc->lines = (char **) calloc(sizeof(char *), lines + 5);
    fc->readlines = fc->cur_line = 0;
    return fc;
}

void clearFileContent(FileContent *fc) {
    if (!fc) return ;
    for (int i = 0; i <= fc->readlines; i++) {
        if (!fc->lines[i]) continue;
        free(fc->lines[i]);
    }
    free(fc->lines);
    free(fc);
}

int Sunday(int *pre, char *pattern, char *text) {
    int len = strlen(pattern);
    for (int i = 0; pattern[i]; i++) pre[pattern[i]] = len - i;
    int p_len = strlen(pattern), t_len = strlen(text), ind = 0;
    while (ind <= t_len - p_len) {
        int match = 0;
        while (match < p_len && text[ind + match] == pattern[match]) match++;
        if (match == p_len) return 1;
        ind += pre[pattern[ind + len]];
    }
    return 0;
}

int find(char *pattern, FileContent *fc) {
    int pre[512], len = strlen(pattern);
    for (int i = 0; i < 512; i++) pre[i] = len + 1;
    for (int i = 1; i <= 1 && i <= fc->readlines; i++) {
        //printf("%s", fc->lines[i]);
        if (Sunday(pre, pattern, fc->lines[i])) return 1;
    }
    return 0;
}

int FileLines(char *filename) {
    FILE *fp;
    int line = 0;
    if (!(fp = fopen(filename, "r"))) {
        perror("fopen");
        exit(1);
    }
    while (!feof(fp)) {
        if (fgetc(fp) == '\n') line++;
    }
    fclose(fp);
    return line;
}

void more(char *filename) {
    FILE *fp;
    //printf("%s\n", filename);
    if (!(fp = fopen(filename, "r"))) {
        perror("fopen");
        exit(1);
    }
    int lines = FileLines(filename);
    FileContent *fc = NewFileContent(lines);
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        fc->lines[++(fc->readlines)] = line;
        fc->cur_line++;
        line = NULL;
    }
    char pattern[100] = "Linux Programmer's Manual";
    printf("find %s ? %s\n", pattern, find(pattern, fc) ? "Yes" : "No");
    /*for (int i = 1; i <= fc->readlines; i++) {
        printf("%s", fc->lines[i]);
    }*/
    fclose(fp);
}

int main(int argc, char **argv) {
    while (--argc) {
        more(*(++argv));
    }
    return 0;
}
