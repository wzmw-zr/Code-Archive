/*************************************************************************
	> File Name: 7.stdin.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月21日 星期六 22时21分24秒
 ************************************************************************/

#include<stdio.h>

int main(int argc, char **argv) {
    char c;
    while ((c = fgetc(stdin)) != EOF) printf("%c", c);
    return 0;
}
