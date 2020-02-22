/*************************************************************************
	> File Name: 1.zombie.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月18日 星期二 01时06分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int num, f;
} Node;

typedef struct heap {
    Node *data;
    int size, cnt;
} Heap;

Node *NewNode(int num, int f) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->num = num;
    node->f = f;
    return node;
}

Heap *NewHeap(int size) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->data = (Node *) malloc(sizeof(Node) * (size + 1));
    heap->size = size;
    heap->cnt = 0;
    return heap;
}

void swap(Node *a, Node *b) {
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}

int cmp(Node a, Node b) {
    if (a.f < b.f) return 0;
    if (a.f == b.f && a.num > b.num) return 0;
    return 1;
}

void push_heap(Heap *heap, Node a) {
    if (!heap) return ;
    if (heap->cnt == heap->size) return ;
    heap->data[++heap->cnt] = a;
    int ind = heap->cnt;
    while (ind >> 1 && cmp(heap->data[ind], heap->data[ind >> 1])) {
        swap(&heap->data[ind] ,&heap->data[ind >> 1]);
        ind >>= 1;
    } 
}

Node top_heap(Heap *heap) {
    return heap->data[1];
}

int empty_heap(Heap *heap) {
    return heap->cnt == 0;
}

void update_heap(Heap *heap) {
    int ind = 1;
    while ((ind << 1) <= heap->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= heap->cnt && cmp(heap->data[l], heap->data[temp])) temp = l;
        if (r <= heap->cnt && cmp(heap->data[r], heap->data[temp])) temp = r;
        if (ind == temp) break;
        swap(&heap->data[ind], &heap->data[temp]);
        ind = temp;
    }
}

void pop_heap(Heap *heap) {
    if (!heap) return ;
    if (empty_heap(heap)) return ;
    swap(&heap->data[1], &heap->data[heap->cnt--]);
    update_heap(heap);
}

void clear_heap(Heap *heap) {
    if (!heap) return ;
    free(heap->data);
    free(heap);
}

int main() {
    int t, n, case_num = 1;
    scanf("%d", &t);
    Heap *heap[101];
    for (int i = 1; i <= 100; i++) {
        heap[i] = NewHeap(50000);
    }
    while (case_num <= t) {
        printf("Case #%d:\n", case_num++);
        scanf("%d", &n);
        Node zombie;
        int f, s;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &f, &s);
            zombie.f = f;
            zombie.num = i;
            push_heap(heap[s], zombie);
        }
        for (int i = 0; i < n; i++) {
            int m = -1;
            Node zombie1, zombie2;
            for (int j = 1; j <= 100; j++) {
                if (empty_heap(heap[j])) continue;
                if (m == -1) {
                    m = j;
                    continue;
                }
                zombie1 = top_heap(heap[m]);
                zombie2 = top_heap(heap[j]);
                zombie1.f += i * s;
                zombie2.f += i * j;
                if (cmp(zombie2, zombie1)) m = j;
            }
            i && printf(" ");
            printf("%d", top_heap(heap[m]).num);
            pop_heap(heap[m]);
        }
        printf("\n");
    }
    for (int i = 1; i <= 100; i++) clear_heap(heap[i]);
    return 0;
}
