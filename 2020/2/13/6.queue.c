/*************************************************************************
	> File Name: 6.queue.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月13日 星期四 22时06分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queue {
    char **tel;
    int size, head, tail;
} Queue;

Queue *init() {
    Queue *q = (Queue *) calloc(sizeof(Queue), 1);
    q->tel = (char **) calloc(sizeof(char *), 10);
    for (int i = 0; i < 10; i++) q->tel[i] = (char *) calloc(sizeof(char), 15);
    q->size = 10;
    q->head = q->tail = 0;
    return q;
}

void push(Queue *q, char *tel) {
    if (!q) return ;
    if (q->tail == q->size) return ;
    strcpy(q->tel[q->tail++], tel); 
    return ;
}


void clear(Queue *q) {
    if (!q) return ;
    free(q->tel);
    free(q);
    return ;
}

int main() {
    Queue *unget = init(), *get = init(), *post = init();
    int type;
    char *tel = (char *) calloc(sizeof(char), 15);
    for (int i = 1; i <= 10; i++) {
        scanf("%d ", &type);
        memset(tel, 0, sizeof(char) * 15);
        scanf("%s", tel);
        switch (type) {
            case 0: push(unget, tel); break;
            case 1: push(get, tel); break;
            case 2: push(post, tel); break;
        }
    }
    for (int i = 1; i <= 10; i++) {
        if (i <= unget->tail - unget->head) printf("%s ", unget->tel[i - 1]);
        else printf("0 ");
        if (i <= get->tail - get->head) printf("%s ", get->tel[i - 1]);
        else printf("0 ");
        if (i <= post->tail - post->head) printf("%s\n", post->tel[i - 1]);
        else printf("0\n");
    }
    return 0;
}
