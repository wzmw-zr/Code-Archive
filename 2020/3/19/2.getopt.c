/*************************************************************************
	> File Name: 2.getopt.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月19日 星期四 23时00分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int flag_a, flag_b, flag_c, flag_d;

int main(int argc, char **argv) {
    int t_argc = argc, opt;
    char **t_argv = argv;
    while ((opt = getopt(argc, argv, "abcd")) != -1) {
        switch (opt) {
            case 'a': flag_a = 1; break;
            case 'b': flag_b = 1; break;
            case 'c': flag_c = 1; break;
            case 'd': flag_d = 1; break;
            default : {
                fprintf(stderr, "Usage : %s [-abcd] name\n", argv[0]);
                exit(1);
            }
        }
    }
    while (t_argc--) {
        printf("%s ", *(t_argv++));
    }
    printf("\n");
    return 0;
}
