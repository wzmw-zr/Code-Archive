/*************************************************************************
	> File Name: 2.zombie.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月18日 星期二 08时16分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int num, f;
} Node;

typedef struct Heap {
    Node *node;
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
    heap->node = (Node *) malloc(sizeof(Node) * (size + 1));
    heap->size = size;
    heap->cnt = 0;
    return heap;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

int cmp(Node a, Node b) {
    if (a.f > b.f) return 1;
    if (a.f == b.f && a.num < b.num) return 1;
    return 0;
}

int empty(Heap *heap) {
    return heap->cnt == 0;
}

Node top(Heap *heap) {
    return heap->node[1];
}

void push(Heap *heap, Node node) {
    if (!heap) return ;
    if (heap->cnt == heap->size) return ;
    heap->node[++heap->cnt] = node;
    int ind = heap->cnt;
    while (ind >> 1 && cmp(heap->node[ind], heap->node[ind >> 1])) {
        swap(&heap->node[ind], &heap->node[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

void update(Heap *heap) {
    int ind = 1;
    while ((ind << 1) <= heap->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= heap->cnt && cmp(heap->node[l], heap->node[temp])) temp = l;
        if (r <= heap->cnt && cmp(heap->node[r], heap->node[temp])) temp = r;
        if (ind == temp) break;
        swap(&heap->node[ind], &heap->node[temp]);
        ind = temp;
    }
    return ;
}

void pop(Heap *heap) {
    if (!heap) return ;
    if (empty(heap)) return ;
    swap(&heap->node[1], &heap->node[heap->cnt--]);
    update(heap);
    return ;
}

void clearNode(Node *node) {
    if (!node) return ;
    free(node);
    return ;
}

void clearHeaap(Heap *heap) {
    if (!heap) return ;
    free(heap->node);
    free(heap);
    return ;
}

int main() {
    int t, n, f, s, case_num = 1;
    Heap *speed[101];
    Node node;
    for (int i = 1; i <= 100; i++) speed[i] = NewHeap(50000);
    scanf("%d", &t); 
    while (t--) {
        printf("Case #%d:\n", case_num++);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &f, &s);
            node.num = i;
            node.f = f;
            push(speed[s], node);
        }
        for (int i = 0; i < n; i++) {
            Node zombie1, zombie2;
            int flag = -1;
            for (int j = 1; j <= 100; j++) {
                if (empty(speed[j])) continue;
                if (flag == -1) {
                    flag = j;
                    zombie1 = top(speed[j]);
                    continue;
                }
                zombie1 = top(speed[flag]);
                zombie2 = top(speed[j]);
                zombie1.f += i * flag;
                zombie2.f += i * j;
                if (cmp(zombie2, zombie1)) flag = j;
            }
            i && printf(" ");
            printf("%d", top(speed[flag]).num);
            pop(speed[flag]);
        }
        printf("\n");
    }
    return 0;
}
