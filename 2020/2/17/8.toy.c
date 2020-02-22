/*************************************************************************
	> File Name: 8.toy.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月17日 星期一 17时24分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct heap {
    double *data;
    int size, cnt;
} Heap;

Heap *init(int n) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->data = (double *) malloc(sizeof(double) * (n + 1));
    heap->size = n;
    heap->cnt = 0;
    return heap;
}

int empty(Heap *heap) {
    return heap->cnt == 0;
}

float top(Heap *heap) {
    return heap->data[1];
}

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(Heap *heap, double val) {
    if (!heap) return ;
    if (heap->cnt == heap->size) return ;
    heap->data[++heap->cnt] = val;
    int ind = heap->cnt;
    while (ind >> 1 && heap->data[ind] > heap->data[ind >> 1]) {
        swap(&heap->data[ind], &heap->data[ind >> 1]);
        ind >>= 1;
    } 
    return ;
}

void pop(Heap *heap) {
    if (!heap) return ;
    if (empty(heap)) return ;
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
    return ;
}

void clear(Heap *heap) {
    if (!heap) return ;
    free(heap->data);
    free(heap);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    Heap *heap = init(n);
    for (int i = 1; i <= n; i++) {
        double val;
        scanf("%lf", &val);
        push(heap, val);
    }
    while (heap->cnt > 1) {
        double a = top(heap); 
        pop(heap);
        double b = top(heap);
        pop(heap);
        double c = pow(a * b * b, 1.0 / 3.0);
        push(heap, c);
    }
    printf("%lf\n", top(heap));
    return 0;
}
