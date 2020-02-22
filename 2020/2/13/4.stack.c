/*************************************************************************
	> File Name: 4.stack.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月13日 星期四 20时14分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    return s->data[s->top];
}

int expand(Stack *s) {
    int num = s->size;
    int *p = s->data;
    while (num) {
        s->data = (int *) realloc(p, sizeof(int) * (s->size + num)); 
        if (s->data) break;
        num /= 2;
    }
    if (s->data) {
        s->size += num;
        return 1;
    }
    s->data = p;
    return 0;
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) if (!expand(s)) return 0;
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s) {
    if (!s) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}


void output(Stack *s) {
    printf("stack(%d) = [", s->top + 1);
    for (int i = 0; i <= s->top; i++) {
        i && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    int op, val;
    Stack *s = init(max_op);
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to stack = %d\n", val, push(s, val));
            } break;
            case 3: {
                printf("pop %d ", top(s));
                printf("from stack = %d\n", pop(s));
            } break;
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}
