/*************************************************************************
	> File Name: 3.stable.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 16时15分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *) malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    printf("%s = ", #func);\
    func(args);\
    output(arr, n);\
    memcpy(arr, num, sizeof(int) * n);\
    free(num);\
}

void insert_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) continue;
            flag = 1;
            swap(arr[j], arr[j + 1]);
        }
        if (!flag) break;
    }
}

void merge(int *arr, int l, int r) {
    int mid = (l + r) >> 1;
    int p1 = l, p2 = mid + 1, temp[r - l + 1], i = 0;
    while (p1 <= mid || p2 <= r) {
        if (p1 <= mid && (p2 > r || arr[p1] < arr[p2])) temp[i++] = arr[p1++];
        else temp[i++] = arr[p2++];
    }
    memcpy(arr + l, temp, sizeof(int) * (r - l + 1));
}

void merge_sort(int *arr, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, r);
}

void randint(int *arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 100;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    randint(arr, max_op);
    TEST(arr, max_op, insert_sort, arr, max_op);
    TEST(arr, max_op, bubble_sort, arr, max_op);
    TEST(arr, max_op, merge_sort, arr, 0, max_op - 1);
    return 0;
}
