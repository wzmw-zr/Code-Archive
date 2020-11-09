/*************************************************************************
	> File Name: 3.HOJ211.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 10时13分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 30
#define max_l 40
using namespace std;

typedef struct toy {
    int num;
    char name[max_n + 5][max_l + 5] = {0};
} Toy;

Toy t;

void reverse(char *a) {
    int len = strlen(a);
    int i = 0, j = len - 1;
    while (i <= j) {
        char c = a[i];
        a[i] = a[j];
        a[j] = c;
        i++, j--;
    }
}

void sort_name() {
    for (int i = 1; i <= t.num; i++) {
        for (int j = 1; j <= t.num - i; j++) {
            if (strcmp(t.name[j], t.name[j + 1]) <= 0) continue;
            char temp[max_l + 5] = {0};
            strcpy(temp, t.name[j]);
            strcpy(t.name[j], t.name[j + 1]);
            strcpy(t.name[j + 1], temp);
        }
    }
    for (int i = 1; i <= t.num; i++) {
        i == t.num && printf("%s", t.name[i]);
        i != t.num && printf("%s\n", t.name[i]);
    }
}

int main() {
    scanf("%d", &t.num);
    for (int i = 1; i <= t.num; i++) scanf("%s", t.name[i]);
    for (int i = 1; i <= t.num; i++) reverse(t.name[i]);
    sort_name();
    return 0;
}
