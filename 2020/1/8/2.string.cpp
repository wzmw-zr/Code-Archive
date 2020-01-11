/*************************************************************************
	> File Name: 2.string.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月08日 星期三 10时33分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
using namespace std;

const int MAX_LENGTH = 256;

char* get_letter(void) {
    static char letter[1000000];
    letter[999999] = ' ';
    char *p = letter;
    int size = MAX_LENGTH;
    while (feof(stdin) == 0) {
        if (size == 0) {
            break;
        }
        fgets(p, size + 1, stdin);
        while (*p != '\0') {
            p++;
            size--;
        }
    }
    return letter;
}

int main() {
    char *str = get_letter();
    char temp[1000000];
    strcpy(temp, str);
    char *token = strtok(temp, "\t\n\"',. ");
    int cnt = 0;
    while (token) {
        printf("%s\n", token);
        if (strcmp(token, "love") == 0) cnt++;
        token = strtok(NULL, "\t\n\"',. ");
    }
    printf("%d\n", cnt);
    puts(str);
    return 0;
}
