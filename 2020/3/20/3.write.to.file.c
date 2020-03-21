/*************************************************************************
	> File Name: 2.write.to.file.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月20日 星期五 13时50分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char **argv) {
    char pathname[100] = "input1";
    const char word[100] = "abcdefg   hijklmn\niiiiii";
    FILE *fp = fopen(pathname, "w+");
    if (!fp) {
        perror("fopen");
        exit(1);
    }
    if (fputs(word, fp) < 0) {
        perror("fputs");
        exit(1);
    }
    FILE *ttyfp = fopen("/dev/tty1", "a+");
    if (ttyfp == NULL) {
        perror("fopen");
        exit(1);
    }
    fputs(word, ttyfp);
    fclose(ttyfp);
    fclose(fp);
    return 0;
}
