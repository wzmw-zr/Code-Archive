/*************************************************************************
	> File Name: 3.stone.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月18日 星期二 09时09分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stone {
    int p, d;
} Stone;

typedef struct Heap {
    Stone *stone;
    int size, cnt;
} Heap;

Stone *NewStone(int d ,int val) {
    Stone *s = (Stone *) malloc(sizeof(Stone));
    s->d = d;
    s->p = val;
    return s;
}

Heap *NewHeap(int size) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->stone = (Stone *) malloc(sizeof(Stone) * (size + 1));
    heap->size = size;
    heap->cnt = 0;
    return heap;
}

int cmp(Stone a, Stone b) {
    if (a.p < b.p) return 1;
    if (a.p == b.p && a.d < b.d) return 1;
    return 0;
}

void swap(Stone *a, Stone *b) {
    Stone temp = *a;
    *a = *b;
    *b = temp;
}

int empty(Heap *heap) {
    return heap->cnt == 0;
}

void push(Heap *heap, Stone s) {
    if (!heap) return ;
    if (heap->cnt == heap->size) return ;
    heap->stone[++heap->cnt] = s;
    int ind = heap->cnt;
    while (ind >> 1 && cmp(heap->stone[ind], heap->stone[ind >> 1])) {
        swap(&heap->stone[ind], &heap->stone[ind >> 1]);
        ind >>= 1;
    } 
}

Stone top(Heap *heap) {
    return heap->stone[1];
}

void update(Heap *heap) {
    if (!heap) return ;
    int ind = 1;
    while ((ind << 1) <= heap->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= heap->cnt && cmp(heap->stone[l], heap->stone[temp])) temp = l;
        if (r <= heap->cnt && cmp(heap->stone[r], heap->stone[temp])) temp = r;
        if (ind == temp) break;
        swap(&heap->stone[ind], &heap->stone[temp]);
        ind = temp;
    }
}

void pop(Heap *heap) {
    if (!heap) return ;
    if (empty(heap)) return ;
    swap(&heap->stone[1], &heap->stone[heap->cnt--]);
    update(heap);
}

void clearStone(Stone *s) {
    if (!s) return ;
    free(s);
}

void clearHeap(Heap *heap) {
    if (!heap) return ;
    free(heap->stone);
    free(heap);
}

int main() {
    #define max_n 100000
    int t, n, p, d;
    Heap *heap = NewHeap(max_n);
    Stone s;
    scanf("%d", &t);
    while (t--) {
        int length = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &p, &d);
            s.p = p;
            s.d = d;
            push(heap, s);
        }
        int num = 1;
        while (!empty(heap)) {
            if (!((num++) % 2))  {
                s = top(heap);
                length = s.p;
                pop(heap);
            } else {
                s = top(heap);
                pop(heap);
                s.p += s.d;
                push(heap, s);
            }
        }
        printf("%d\n", length);
    }
    return 0;
}
