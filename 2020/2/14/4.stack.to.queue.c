/*************************************************************************
	> File Name: 4.queue.to.stack.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月14日 星期五 14时08分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 100


typedef struct myqueue {
    int *data;
    int size, top;
} MyQueue;

MyQueue *init() {
    MyQueue *q = (MyQueue *) malloc(sizeof(MyQueue));
    q->data = (int *) malloc(sizeof(int) * max_n);
    q->size = max_n;
    q->top = -1;
    return q;
}

int empty(MyQueue *q) {
    return q->top == -1;
}

void push(MyQueue *q, int val) {
    if (!q) return ;
    if (q->top + 1 == q->size) return ;
    q->data[++q->top] = val;
    return ;
}

int pop(MyQueue *q) {
    int ret = q->data[0];
    for (int i = 0; i < q->top; i++) q->data[i] = q->data[i + 1]; 
    q->top--;
    return ret;
}

int front(MyQueue *q) {
    return q->data[0];
}


void clear(MyQueue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {

    return 0;
}
