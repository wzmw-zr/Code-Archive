/*************************************************************************
	> File Name: 2.sunday.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月26日 星期三 10时29分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define TEST(func, a, b) {\
    printf("%s(%s, %s) = %d\n", #func, a, b, func(a, b));\
}

int sunday(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int offset[128];
    for (int i = 0; i < 128; i++) offset[i] = len2 + 1;
    for (int i = 0; i < len2; i++) offset[t[i]] = len2 - i;
    printf("offset = [");
    for (int i = 0; i < 128; i++) printf("%d ", offset[i]);
    printf("]\n");
    for (int i = 0; i < len1 - len2 + 1;) {
        int flag = 1;
        for (int j = 0; j < len2; j++) {
            if (s[i + j] == t[j]) continue;
            i += offset[s[i + len2]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int main() {
    char s[1000] = {0}, t[1000] = {0};
    scanf("%s%s", s, t);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    TEST(sunday, s, t);
    return 0;
}
