/*************************************************************************
	> File Name: 2.HOJ210.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 09时57分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 26
using namespace std;

typedef struct word {
    int num;
    char words[max_n + 5][15];
} Word;

Word w;

int cmp(char *a, char *b) {
    if (strcmp(a, b) >= 0) return 0;
    return 1;
}

void sort_word() {
    for (int i = 1; i <= w.num; i++) {
        for (int j = 1; j <= w.num - i; j++) {
            if (strcmp(w.words[j], w.words[j + 1]) <= 0) continue;
            char temp[15];
            strcpy(temp, w.words[j]);
            strcpy(w.words[j], w.words[j + 1]);
            strcpy(w.words[j + 1], temp);
        }
    }
}

int main() {
    scanf("%d", &w.num);
    for (int i = 1; i <= w.num; i++) {
        scanf("%s", w.words[i]);
    }
    sort_word();
    for (int i = 1; i <= w.num; i++) {
        i == w.num && printf("%s", w.words[i]);
        i != w.num && printf("%s ", w.words[i]);
    }
    return 0;
}
