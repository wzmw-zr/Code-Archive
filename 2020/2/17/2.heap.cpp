/*************************************************************************
	> File Name: 2.heap.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月17日 星期一 11时02分33秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct heap {
    int *data;
    int size, cnt;
} Heap;

Heap *init(int n) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->data = (int *) malloc(sizeof(int) * (n + 1));
    heap->size = n;
    heap->cnt = 0;
    return heap;
}

int empty(Heap *heap) {
    return heap->cnt == 0;
}

int top(Heap *heap) {
    return heap->data[1];
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(Heap *heap, int val) {
    if (!heap) return ;
    heap->data[++heap->cnt] = val;
    int ind = heap->cnt;
    while (ind >> 1) {
        if (heap->data[ind] <= heap->data[ind >> 1]) break;
        swap(&heap->data[ind], &heap->data[ind >> 1]);
    }
    return ;
}

void pop(Heap *heap) {
    if (!heap) return ;
    if (empty(heap)) return ;
    swap(&heap->data[1], &heap->data[heap->cnt--]);
    int ind = 1;
    while (ind << 1 <= heap->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (heap->data[temp] < heap->data[l]) temp = l;
        if (r <= heap->cnt && heap->data[temp] < heap->data[r]) temp = r;
        if (temp == ind) break;
        swap(&heap->data[ind], &heap->data[temp]);
        ind = temp;
    }
    return ;
}

void clear(Heap *heap) {
    if (!heap) return ;
    free(heap->data);
    free(heap);
    return ;
}

int main() {
    srand(time(0)); 
    #define max_op 10
    Heap *heap = init(max_op);
    for (int i = 1; i <= max_op; i++) {
        int val = rand() % 100;
        push(heap, val);
    }
    while (!empty(heap)) pop(heap);
    for (int i = 1; i <= max_op; i++) printf("%d ", heap->data[i]);
    printf("\n");
    return 0;
}
