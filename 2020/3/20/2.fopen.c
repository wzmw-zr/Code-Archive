/*************************************************************************
	> File Name: 2.fopen.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月20日 星期五 08时20分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

FILE *fp;
char *line;
size_t len;
ssize_t size;
int cnt;

typedef struct LineOfFile {
    char **lines;
    int cnt;
} LineOfFile;

LineOfFile FileLine;

void CountLine(FILE *fp) {
    while (!feof(fp)) {
        if (fgetc(fp) == '\n') (FileLine.cnt)++;
    }
}

int main(int argc, char **argv) {
    while (--argc) {
        if ((fp = fopen(*(++argv), "r"))) {
            CountLine(fp);
            fclose(fp);
            fp = fopen(*argv, "r");
            FileLine.lines = (char **) calloc(sizeof(char *), FileLine.cnt);
            while (getline(&line, &size, fp) != -1) {
                FileLine.lines[cnt++] = line; 
                line = NULL;
                size = 0;
            } 
        } else {
            perror("fopen");
            exit(1);
        }
    }    
    FILE *fptty;
    if ((fptty = fopen("/dev/tty", "a+")) == NULL) {
        perror("fopen");
        exit(1);
    }
    for (int i = 0; i < cnt; i++) printf("%s", FileLine.lines[i]);
    while (1);
    return 0;
}

