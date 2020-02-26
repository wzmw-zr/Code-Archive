/*************************************************************************
	> File Name: 3.shift_and.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月26日 星期三 15时01分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define TEST(func, a, b) {\
    printf("%s(%s, %s) = %d\n", #func, a, b, func(a, b));\
}

int shift_and(char *s, char *t) {
    int code[128] = {0};
    int len = 0;
    for (len = 0; t[len]; len++) {
        code[t[len]] |= (1 << len);
    }
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & code[s[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
}

int main() {
    char s[1000], t[1000];
    scanf("%s%s", s, t);
    TEST(shift_and, s, t);
    return 0;
}
