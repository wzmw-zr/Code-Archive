/*************************************************************************
	> File Name: 11.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月18日 星期二 00时11分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int num, val;
} Node;

typedef struct heap {
    Node *node;
    int size, cnt;
} Heap;

Node *NewNode(int num, int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->num = num;
    node->val = val;
    return node;
}

Heap *NewHeap(int size) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->node = (Node *) malloc(sizeof(Node));
    heap->size = size;
    heap->cnt = 0;
    return heap;
}

void clearNode(Node *node) {
    free(node);
}

void clearHeap(Heap *heap) {
    free(heap->node);
    free(heap);
}

int main() {
    Heap *heap = NewHeap(20); 
    Node *node = NewNode(10, 30);
    Node temp;
    temp = *node;
    printf("temp.val = %d\n", temp.val);
    /*for (int i = 1; i <= 10; i++) {
        Node *node = NewNode(i, 2 * i);
        heap->node[i] = *node;
    }
    for (int i = 1; i <= 10; i++) {
        printf("heap->node[%d].val = %d\n", i, heap->node[i].val);
    }*/
    return 0;
}
