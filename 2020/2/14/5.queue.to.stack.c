/*************************************************************************
	> File Name: 5.queue.to.stack.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月14日 星期五 14时30分09秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 10000

typedef struct mystack {
    int *data;
    int head, tail, size, cnt;
} MyStack;

MyStack *init() {
    MyStack *s = (MyStack *) malloc(sizeof(MyStack));
    s->data = (int *) malloc(sizeof(int) * max_n);
    s->head = s->tail = s->cnt = 0;
    s->size = max_n;
    return s;
}

int empty(MyStack *s) {
    return s->cnt == 0;
}


void push(MyStack *s, int val) {
    if (!s) return ;
    if (s->cnt == s->size) return ;
    s->data[s->tail++] = val;
    s->cnt++;
    return ;
}

int pop(MyStack *q) {
    if (!q) return 0;
    if (empty(q)) return 0;
    int ret = q->data[q->tail - 1];
    for (int i = 1; i < q->cnt; i++) q->data[q->tail - i] = q->data[q->tail - i - 1];
    q->cnt--;
    q->head++;
    return ret;
}

int top(MyStack *s) {
    return s->data[s->tail - 1];
}

void output(MyStack *s) {
    printf("mystack(%d) = [", s->cnt);
    for (int i = 0; i < s->cnt; i++) {
        i && printf(", ");
        printf("%d", s->data[s->head + i]);
    }
    printf("]\n");
}

void clear(MyStack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}



int main() {
    MyStack *s = init();
    for (int i = 1; i <= 10; i++) push(s, i); 
    output(s);
    printf("top = %d\n", top(s));
    printf("pop %d\n", pop(s));
    output(s);
    printf("pop %d\n", pop(s));
    output(s);
    printf("pop %d\n", pop(s));
    output(s);
    return 0;
}
