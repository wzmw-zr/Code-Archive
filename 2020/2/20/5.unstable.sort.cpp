/*************************************************************************
	> File Name: 5.unstable.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 18时31分12秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a) __temp = (a);\
    (a) = (b); (b) = __temp;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *) malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

void select_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[ind]) ind = j;
        }
        swap(arr[i], arr[ind]);
    }
}

void quick_sort(int *arr, int l, int r) {
    if (l >= r) return ;
    int base = arr[l], x = l, y = r;
    while (x < y) {
        while (x < y && arr[y] >= base) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= base) x++;
        if (x < y) arr[y--] = arr[x];
    }
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);
}

void randint(int *arr,int n) {
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
    TEST(arr, max_op, select_sort, arr, max_op);
    TEST(arr, max_op, quick_sort, arr, 0, max_op - 1);
    return 0;
}
