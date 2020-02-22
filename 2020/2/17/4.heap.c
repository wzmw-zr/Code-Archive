/*************************************************************************
	> File Name: 4.heap.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月17日 星期一 14时31分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Heap {
    int *data, size, cnt;
} Heap;

Heap *init(int n) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->data = (int *) malloc(sizeof(int) * (n + 1));
    heap->size = n;
    heap->cnt = 0;
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int top(Heap *heap) {
    return heap->data[1];
}

void push(Heap *heap, int val) {
    heap->data[++heap->cnt] = val;
    printf("val = %d\n", val);
    int ind = heap->cnt;
    while (ind >> 1) {
        if (heap->data[ind] <= heap->data[ind >> 1]) break; 
        swap(&heap->data[ind], &heap->data[ind >> 1]);
        ind >>= 1; 
    }
}

void pop(Heap *heap) {
    swap(&heap->data[1], &heap->data[heap->cnt--]);
    int ind = 1;
    while ((ind << 1) <= heap->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (heap->data[temp] < heap->data[l]) temp = l;
        if (r <= heap->cnt && heap->data[temp] < heap->data[r]) temp = r;
        if (temp == ind) break;
        swap(&heap->data[ind], &heap->data[temp]);
        ind = temp;
    }
    heap->size--;
    return ;
}

void heap_sort(Heap *heap) {
    for (int i = 1; i <= heap->size; i++) pop(heap);
}

void clear(Heap *heap) {
    if (!heap) return ;
    free(heap->data);
    free(heap);
}

int main() {
    int n, m, x;
    scanf("%d", &n);
    Heap *heap = init(n);
    for (int i = 1; i <= n; i++)  {
        scanf("%d", &x);
        push(heap, x);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", top(heap));
        pop(heap);
    } 
    int cnt = heap->size;
    for (int i = 1; i <= cnt; i++) printf("%d ", heap->data[i]);
    printf("\n");
    heap_sort(heap);
    for (int i = 1; i <= cnt; i++) printf("%d ", heap->data[i]);
    printf("\n");
    return 0;
}
