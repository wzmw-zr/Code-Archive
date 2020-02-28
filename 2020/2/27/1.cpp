/*************************************************************************
	> File Name: 1.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月27日 星期四 20时00分34秒
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;


bool isValid(char * s){
    int len = strlen(s);
    char *stack = (char *) calloc(sizeof(char), (len + 5));
    int top = -1, flag = 1;
    while (s[0]) {
        printf("%c\n", s[0]);
        switch (s[0]) {
            case '(':
            case '[':
            case '{': stack[++top] = s[0]; break;
            case ')': flag = (top != -1 && stack[top--] == '('); break;
            case ']': flag = (top != -1 && stack[top--] == '['); break;
            case '}': flag = (top != -1 && stack[top--] == '{'); break;
        }
        printf("flag = %d\n", flag);
        if (!flag) return false;
        s++;
    }
    if (top != -1) return false;
    free(stack);
    return true;
}

int main() {
    char s[100] = {0};
    scanf("%s", s);
    printf("%d\n", isValid(s));
}
