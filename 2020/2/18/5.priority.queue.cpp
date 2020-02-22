/*************************************************************************
	> File Name: 5.priority.queue.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月18日 星期二 16时31分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct priority_queue {
    int *data;
    int size, cnt;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *) malloc(sizeof(priority_queue));
    q->data = (int *) malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

void push(priority_queue *q, int val) {
    if (!q) return;
    if (q->cnt == q->size) return ;
    q->data[++q->cnt] = val;
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(&q->data[ind], &q->data[ind >> 1]);
        ind >>= 1;
    }
}

void update(priority_queue *q) {
    if (!q) return ;
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= q->cnt && q->data[temp] < q->data[l]) temp = l;
        if (r <= q->cnt && q->data[temp] < q->data[r]) temp = r;
        if (ind == temp) break;
        swap(&q->data[ind], &q->data[temp]);
        ind = temp;
    }
}

void pop(priority_queue *q) {
    if (!q) return ;
    if (empty(q)) return ;
    swap(&q->data[1], &q->data[q->cnt--]);
    update(q);
}

void clear_queue(priority_queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
}

int main() {
    srand(time(0));
    #define max_op 20
    priority_queue *q = init(max_op);
    for (int i = 1; i <= max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d to queue\n", val);
    }
    for (int i = 0; i < max_op; i++) {
        i && printf(" ");
        printf("%d", top(q));
        pop(q);
    }
    printf("\n");
    clear_queue(q);
    return 0;
}
