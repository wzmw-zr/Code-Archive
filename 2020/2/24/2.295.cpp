/*************************************************************************
	> File Name: 2.295.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月24日 星期一 14时06分02秒
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Heap {
    int *data, size, cnt;
} Heap;

typedef struct {
    Heap *left, *right;
} MedianFinder;

void swap(int *a, int *b) {
    int temp =*a;
    *a = *b;
    *b = temp;
}

Heap *initHeap() {
    Heap *h = (Heap *) malloc(sizeof(Heap));
    h->data = (int *) calloc(sizeof(int), 10001);
    h->size = 10000;
    h->cnt = 0;
    return h;
}

void expand(Heap *h) {
    if (!h) return ;
    int exp_size = h->size, *p;
    while (exp_size) {
        p = (int *) realloc(h->data, sizeof(int) * (h->size + exp_size + 5)); 
        if (p) break;
        exp_size >>= 1;
    }
    if (p) {
        h->data = p;
        h->size += exp_size;
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder *m = (MedianFinder *) malloc(sizeof(MedianFinder)); 
    m->left = initHeap(); 
    m->right = initHeap();
    return m;
}

void max_insert(Heap *h, int val) {
    if (h->cnt == h->size) expand(h);
    h->data[++h->cnt] = val;
    int ind = h->cnt;
    while (ind >> 1 && h->data[ind] > h->data[ind >> 1]) {
        swap(&h->data[ind], &h->data[ind >> 1]);
        ind >>= 1;
    } 
}

void min_insert(Heap *h, int val) {
    if (h->cnt == h->size) expand(h);
    h->data[++h->cnt] = val;
    int ind = h->cnt;
    while (ind >> 1 && h->data[ind] < h->data[ind >> 1]) {
        swap(&h->data[ind], &h->data[ind >> 1]);
        ind >>= 1;
    } 
}

int min_pop(Heap *h) {
    int ret = h->data[1];
    h->data[1] = h->data[h->cnt--];
    int ind = 1;
    while ((ind << 1) <= h->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= h->cnt && h->data[temp] > h->data[l]) temp = l;
        if (r <= h->cnt && h->data[temp] > h->data[r]) temp = r;
        if (ind == temp) break;
        swap(&h->data[ind], &h->data[temp]);
        ind = temp;
    }
    return ret;
}

int max_pop(Heap *h) {
    int ret = h->data[1];
    h->data[1] = h->data[h->cnt--];
    int ind = 1;
    while ((ind << 1) <= h->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= h->cnt && h->data[temp] < h->data[l]) temp = l;
        if (r <= h->cnt && h->data[temp] < h->data[r]) temp = r;
        if (ind == temp) break;
        swap(&h->data[ind], &h->data[temp]);
        ind = temp;
    }
    return ret;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->right->cnt == 0) {
        min_insert(obj->right, num);
        return ;
    }
    if (obj->left->cnt == 0) {
        if (obj->right->data[1] > num) max_insert(obj->left, num);
        else {
            obj->left->data[1] = obj->right->data[1];
            obj->right->data[1] = num;
            obj->left->cnt++;
        }
        return ;
    }
    if (num > obj->right->data[1]) {
        if (obj->left->cnt == obj->right->cnt) {
            int number = min_pop(obj->right);
            max_insert(obj->left, number);
            min_insert(obj->right, num);
        }
        else {
            min_insert(obj->right, num);
        }
    } else {
        if (obj->left->cnt == obj->right->cnt) {   
            max_insert(obj->left, num);
        } else {
            int number = max_pop(obj->left);
            if (number < num) swap(&number, &num);
            min_insert(obj->right, number);
            max_insert(obj->left, num);
        }
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->left->cnt < obj->right->cnt) return (double) obj->right->data[1];
    if (obj->left->cnt > obj->right->cnt) return (double) obj->left->data[1];
    return ((double) obj->left->data[1] + (double) obj->right->data[1]) / 2;
}

void clearHeap(Heap *h) {
    if (!h) return ;
    free(h->data);
    free(h);
}

void medianFinderFree(MedianFinder* obj) {
    if (!obj) return ;
    clearHeap(obj->left);
    clearHeap(obj->right);
    free(obj);
}

void output(Heap *h) {
    printf("[");
    for (int i = 1; i <= h->cnt; i++) printf("%d ", h->data[i]);
    printf("]\n");
}

int main() {
    MedianFinder *m = medianFinderCreate();
    m->left = initHeap(), m->right = initHeap();
    int num;
    for (int i = 1; i <= 41; i++) {
        scanf("%d", &num); 
        medianFinderAddNum(m, num);    
        output(m->left);
        output(m->right);
        printf("%lf\n", medianFinderFindMedian(m));
        printf("\n");
    }
    return 0;
}
