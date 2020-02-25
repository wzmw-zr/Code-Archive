/*************************************************************************
	> File Name: 1.703.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月24日 星期一 00时11分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Heap {
    int *data, size, cnt;
} Heap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap *init(int size) {
    Heap *h = (Heap *) malloc(sizeof(Heap));
    h->data = (int *) malloc(sizeof(int) * (size + 1));
    h->size = size;
    h->cnt = 0;
    return h;
}

void update(Heap *h, int p) {
    int ind = p;
    while ((ind << 1) <= h->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= h->cnt && h->data[temp] > h->data[l]) temp = l;
        if (r <= h->cnt && h->data[temp] > h->data[r]) temp = r;
        if (temp == ind) return ;
        swap(&h->data[ind], &h->data[temp]);
        ind = temp;
    } 
}

void clear(Heap *h) {
    if (!h) return ;
    free(h->data);
    free(h);
}

int main() {
    return 0;
}
