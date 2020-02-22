/*************************************************************************
	> File Name: 9.zombie.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月17日 星期一 18时58分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 5000

typedef struct zombie {
    int num, f, s;
} Zombie;

typedef struct Heap {
    Zombie **zom;
    int size, cnt;
} Heap;

Zombie *NewZombie(int num, int f, int s) {
    Zombie *z = (Zombie *) malloc(sizeof(Zombie));
    z->num = num;
    z->f = f;
    z->s = s;
    return z;
}

Heap *NewHeap(int num) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->zom = (Zombie **) malloc(sizeof(Zombie *) * (num + 1));
    heap->size = num;
    heap->cnt = 0;
    return heap;
}

int empty(Heap *heap) {
    return heap->cnt == 0;
}

Zombie *top(Heap *heap) {
    return heap->zom[1];
}


void swap(Zombie **a, Zombie **b) {
    Zombie *temp = *a;
    *a = *b;
    *b = temp;
}

void pop(Heap *heap) {
    swap(&heap->zom[1], &heap->zom[heap->cnt--]);
    return ;
}

void push(Heap *heap, Zombie *z) {
    if (!heap) return ;
    if (heap->cnt == heap->size) return ;
    heap->zom[++heap->cnt] = z;
    int ind = heap->cnt;
    while (ind >> 1) {
        if (heap->zom[ind]->f < heap->zom[ind >> 1]->f) break;
        if (heap->zom[ind]->f == heap->zom[ind >> 1]->f && heap->zom[ind]->num > heap->zom[ind >> 1]->num) break;
        swap(&heap->zom[ind], &heap->zom[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

void build(Heap *heap, int ind, int num) {
    while ((ind << 1) <= num) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (heap->zom[temp]->f < heap->zom[l]->f) temp = l;
        if (heap->zom[temp]->f == heap->zom[l]->f && heap->zom[temp]->num > heap->zom[l]->num) temp = l;
        if (r <= num && heap->zom[temp]->f < heap->zom[r]->f) temp = r;
        if (r <= num && heap->zom[temp]->f == heap->zom[r]->f && heap->zom[temp]->num > heap->zom[r]->num) temp = r;
        if (ind == temp) break;
        swap(&heap->zom[ind], &heap->zom[temp]);
        ind = temp;
    }
    return ;
}

void buildHeap(Heap *heap) {
    if (!heap) return ;
    int ind = heap->cnt >> 1;
    while (ind) {
        build(heap, ind--, heap->cnt);
    }
}

void change(Heap *heap) {
    if (!heap) return ;
    if (!heap->cnt) return ;
    for (int i = 1; i <= heap->cnt; i++) {
        heap->zom[i]->f += heap->zom[i]->s;
    }
    return ;
}


void clearZombie(Zombie *zom) {
    if (!zom) return ;
    free(zom);
    return ;
}

void clearHeap(Heap *heap) {
    if (!heap) return ;
    for (int i = 1; i <= heap->cnt; i++) clearZombie(heap->zom[i]);
    free(heap);
    return ;
}

void outputInfo(Heap *heap) {
    for (int i = 1;i <= heap->cnt; i++) {
        printf("heap->zom[%d]->num = %d, heap->zom[%d]->f = %d, heap->zom[%d]->s = %d\n", i, heap->zom[i]->num, i, heap->zom[i]->f, i, heap->zom[i]->s);
    }
    printf("\n");
}

int main() {
    #define max_speed 100
    int t, n, f, s, i = 1;
    scanf("%d", &t);
    Heap *speed[max_speed + 1];
    while (t--) {
        memset(speed, 0, sizeof(Heap *) * (max_speed + 1));
        printf("Case #%d:\n", i++);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &f, &s);  
            if (!speed[s]) speed[s] = NewHeap(n);
            push(speed[s], NewZombie(i, f, s));
        }
        /*for (int i = 1; i <= 100; i++) {
            printf("speed[%d]->cnt = %d\n", i, speed[i]->cnt);
        }*/
        int times = 0;
        while (times < n) {
            Heap *heap = NewHeap(n);
            for (int i = 1; i <= 100; i++) {
                if (!speed[i]) continue;
                if (!speed[i]->cnt) continue;
                push(heap, top(speed[i]));
            }
            //printf("heap->cnt = %d\n", heap->cnt);
            //for (int i = 1; i <= heap->cnt; i++) printf("heap->zom[%d]->f = %d\n", i, heap->zom[i]->f);
            times && printf(" ");
            printf("%d", top(heap)->num);
            for (int i = 1; i <= heap->cnt; i++) heap->zom[i]->f -= heap->zom[i]->s * times;
            pop(speed[top(heap)->s]);
            times++;
            for (int i = 1; i <= 100; i++) {
                if (!speed[i]) continue;
                if (!speed[i]->cnt) continue;
                top(speed[i])->f += i * times;
            }
        }
        printf("\n");
        for (int i = 0; i < max_speed; i++) if (speed[i]) clearHeap(speed[i]);
    }
    return 0;
}
