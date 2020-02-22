#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *data, size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (int *)malloc(sizeof(int) * length_input);
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = current >> 1;
    while (h->data[current] > h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = current >> 1;
    }
    h->size++;
}

void output(Heap *h) {
    for (int i = 1; i < h->size; i++) {
        printf("%d ",  h->data[i]);
    }
    printf("\n");
}

int top(Heap *h) {
    return h->data[1];
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos, rchild = 2 * pos + 1;
    int max_value = pos;
    if (lchild < n && h->data[lchild] > h->data[max_value]) {
        max_value = lchild;
    }
    if (rchild < n && h->data[rchild] > h->data[max_value]) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[pos], &h->data[max_value]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[1], &h->data[h->size]);
    h->size--;
    update(h, 1, h->size);
}

void heap_sort(Heap *h) {
    for (int i = h->size; i >= 1; i--) {
        swap(&h->data[i], &h->data[1]);
        update(h, 1, i);
    }
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int n;
    scanf("%d", &n);
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    init(heap, n);
    for (int i = 1; i <= n; i++) scanf("%d ", &heap->data[i]);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", top(heap));
        pop(heap);
    }
    return 0;
}
