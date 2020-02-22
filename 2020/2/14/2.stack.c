/*************************************************************************
	> File Name: 2.stack.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月14日 星期五 09时29分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack {
    char *data;
    int size, top;
} Stack;

Stack *init(int size) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (char *) malloc(sizeof(char) * size);
    s->size = size;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (!s) return ;
    if (s->top == s->size - 1) return ;
    s->data[++s->top] = c;
    return ;
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

int isValid (char *s) {
    int len = strlen(s), i = 0;
    Stack *stack = init(len);
    while (i < len) {
        char c = s[i];
        switch (c) {
            case '(':
            case '[':
            case '{': {            
                push(stack, c);
            } break;
            case ')': { 
                if (empty(stack) || top(stack) != '(') return 0;
                pop(stack);
            } break;
            case ']': { 
                if (empty(stack) || top(stack) != '[') return 0;
                pop(stack);
            } break;
            case '}': { 
                if (empty(stack) || top(stack) != '{') return 0;
                pop(stack);
            } break;
        }
        i++;
    }
    return 1;
}

int main() {
    char s[100];
    scanf("%s", s);
    printf("isValid ? %d\n", isValid(s));
    return 0;
}
