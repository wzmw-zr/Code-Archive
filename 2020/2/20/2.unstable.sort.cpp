/*************************************************************************
	> File Name: 2.unstable.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 10时12分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void select_sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int ind = i, temp = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (temp > arr[j]) temp = arr[j], ind = j;
        }
        swap(&arr[i], &arr[ind]);
    }
}

void quick_sort(int *arr, int l, int r) {
    if (l >= r) return ;
    int x = l, y = r, z = arr[l];
    while (x < y) {
        while (x < y && arr[y] >= z) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x);
    quick_sort(arr, y + 1, r);
}

void init(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void output(int*arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_n 20
    int arr[max_n];
    init(arr, max_n);
    output(arr, max_n);
    //select_sort(arr, max_n);
    quick_sort(arr, 0, max_n - 1);
    output(arr, max_n);
    return 0;
}
