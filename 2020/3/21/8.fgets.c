/*************************************************************************
	> File Name: 8.fgets.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月21日 星期六 22时43分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char **argv) {
    char word[1000];
    FILE *fp;
    if ((fp = fopen("1.more.c", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }
    printf("word = %s", fgets(word, 1000, fp));
    printf("word = %s", word);
    return 0;
}
