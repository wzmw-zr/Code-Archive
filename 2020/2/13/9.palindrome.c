/*************************************************************************
	> File Name: 9.palindrome.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月13日 星期四 23时14分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 20

typedef struct stack {
    char *data;
    int size, top;
} Stack;

Stack *init() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (char *) malloc(sizeof(char) * (max_n + 5));
    s->size = max_n + 5;
    s->top = -1;
    return s;
}

void push(Stack *s, char c) {
    if (!s) return ;
    if (s->top + 1 == s->size) return ;
    s->data[++s->top] = c;
    return ;
}

int empty(Stack *s) {
    return s->top == -1;
}

void pop(Stack *s) {
    if (!s) return ;
    if (empty(s)) return ;
    s->top--;
    return ;
}

char top(Stack *s) {
    if (!s) return (char) 0;
    if (empty(s)) return (char) 0;
    return s->data[s->top];
}

void clear(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
    Stack *old = init(), *new = init();
    char s[max_n + 5];
    scanf("%s", s);
    for (int i = 0; i < strlen(s) - 1; i++) push(old, s[i]);
    while (!empty(old)) {
        push(new, top(old));
        pop(old);
    }
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (new->data[i] == s[i]) continue;
        printf("false\n");
        return 0;
    }
    printf("true\n");
    return 0;
}
