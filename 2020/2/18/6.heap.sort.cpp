/*************************************************************************
	> File Name: 6.heap.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月18日 星期二 19时24分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a) __temp = (a);\
    (a) = (b); (b) = __temp;\
}

void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (l <= n && arr[temp] < arr[l]) temp = l;
        if (r <= n && arr[temp] < arr[r]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
}

void build(int *arr, int n) {
    for (int i = n >> 1; i >= 1; i--) downUpdate(arr, n, i);
} 

void heap_sort(int *arr, int n) {
    arr--;
    build(arr, n);
    while (n) {
        swap(arr[1], arr[n]);
        downUpdate(arr, --n, 1);
    }
}

void output(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    int *arr = (int *) malloc(sizeof(int) * max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        arr[i] = val;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    return 0;
}
