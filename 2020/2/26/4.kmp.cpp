/*************************************************************************
	> File Name: 4.kmp.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月26日 星期三 15时56分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define TEST(func, a, b) {\
    printf("%s(%s, %s) = %d\n", #func, a, b, func(a, b));\
}

int kmp(char *s, char *t) {
    int *next = (int *) malloc(sizeof(int) * strlen(t));
    next[0] = -1;
    for (int i = 1, j = -1; t[i]; i++) {
        while (j != -1 && t[i] != t[j + 1]) j = next[j];
        if (t[i] == t[j + 1]) j++;
        next[i] = j;
    }
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && s[i] != t[j + 1]) j = next[j];
        if (s[i] == t[j + 1]) j++;
        if (!t[j + 1]) return i - strlen(t) + 1;
    }
    return -1;
}

int main() {
    char s[1000], t[1000];
    scanf("%s%s", s, t);
    TEST(kmp, s, t);
    return 0;
}

