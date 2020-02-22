/*************************************************************************
	> File Name: 1.stack.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月14日 星期五 08时24分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int *data;
    int size, top;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->data = (int *) malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

void push(Stack *s, int val) {
    if (!s) return ;
    if (s->top == s->size - 1) return ;
    s->data[++(s->top)] = val;
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

int top(Stack *s) {
    if (!s) return 0;
    if (empty(s)) return 0;
    return s->data[s->top];
}

void clear(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
    int n, num[105];
    scanf("%d", &n);
    Stack *s = init(n);
    for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
    int i = 1, j = 1;
    while (j <= num[i]) push(s, j), j++;
    while (!empty(s) || i <= n) {
        if (empty(s)) while (j <= num[i]) push(s, j++);
        int top_val = top(s);
        if (top_val == num[i]) pop(s), i++;
        else if (top_val > num[i]) {
            printf("NO\n");
            return 0;
        } else {
            if (top_val < num[i]) while (j <= num[i]) push(s, j++);
        }
    }
    printf("YES\n");
    return 0;
}
