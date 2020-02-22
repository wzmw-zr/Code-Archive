/*************************************************************************
	> File Name: 5.heap.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月17日 星期一 15时55分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(priority_queue *q, int val) {
    if (q->cnt == q->size) return ;
    q->data[++q->cnt] = val;
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(&q->data[ind], &q->data[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

void pop1(priority_queue *q) {
    if (!q) return ;
    if (empty(q)) return ;
    swap(&q->data[1], &q->data[q->cnt--]); 
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[temp] < q->data[l]) temp = l;
        if (r <= q->cnt && q->data[temp] < q->data[r]) temp = r;
        if (temp == ind) break;
        swap(&q->data[temp], &q->data[ind]);
        ind = temp;
    }
    return ;
}

void pop2(priority_queue *q) {
    if (!q) return ;
    if (empty(q)) return ;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[temp] < q->data[l]) temp = l;
        if (r <= q->cnt && q->data[temp] < q->data[r]) temp = r;
        if (temp == ind) break;
        swap(&q->data[temp], &q->data[ind]);
        ind = temp;
    }
    return ;
}

void clear(priority_queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0)); 
    #define max_n 10
    priority_queue *q = init(max_n);
    for (int i = 1; i <= max_n; i++) {
        int val = rand() % 100;
        printf("%d ", val);
        push(q, val);
    }
    printf("\n");
    for (int i = 1; i <= max_n; i++) printf("%d ", q->data[i]);
    printf("\n");
    while (!empty(q)) {
        printf("%d ", top(q));
        pop1(q);
    }
    printf("\n");
    for (int i = 1; i <= max_n; i++) printf("%d ", q->data[i]);
    printf("\n");
    return 0;
}
