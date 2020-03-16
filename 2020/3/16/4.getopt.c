/*************************************************************************
	> File Name: 4.getopt.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月16日 星期一 20时36分49秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a': {
                printf("get option a\n");
            } break;
            case 'l': {
                printf("get option l\n");
            } break;
            default: {
                printf("option error\n");
            } break;
        } 
    }
    while (--argc) {
        printf("%s ", *++argv);
    }
    printf("\n");
    return 0;
}
