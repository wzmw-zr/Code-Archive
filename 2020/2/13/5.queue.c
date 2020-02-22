/*************************************************************************
	> File Name: 5.queue.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月13日 星期四 21时47分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tel {
    int type;
    char TelNumber[15];
} Tel;

typedef struct queue {
    Tel *tel;
    int size, head, tail;
} Queue;

Queue *init() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->tel = (Tel *) malloc(sizeof(Tel) * 10);
    q->size = 10;
    q->head = q->tail = 0;
    return q;
}

int empty(Queue *q) {
    return q->head == q->tail;
}

int push(Queue *q, int type, char *TelNumber) {
    if (!q) return 0;
    if (q->tail == q->size) return 0;
    q->tel[q->tail].type = type;
    strcpy(q->tel[q->tail].TelNumber, TelNumber); 
    q->tail++;
    return 1;
}

Tel *pop(Queue *q) {
    if (!q) return NULL;
    if (empty(q)) return NULL;
    Tel *p = &q->tel[q->head++];
    return p;
} 

void clear(Queue *q) {
    if (!q) return ;
    free(q->tel);
    free(q);
    return ;
}

int main() {
    Queue *q = init();
    int type;
    char TelNumber[15] = {0};
    for (int i = 1; i <= 10; i++) {
        memset(TelNumber, 0, sizeof(int) * 15);
        scanf("%d ", &type);
        scanf("%s\n", TelNumber);
        push(q, type, TelNumber);
    }
    
    return 0;
}
