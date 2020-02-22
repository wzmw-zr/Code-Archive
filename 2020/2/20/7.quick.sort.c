/*************************************************************************
	> File Name: 7.quick.sort.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 19时17分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *arr, int l, int r) {
    if (l >= r) return ;
    int ind = rand() % (r - l + 1);
    swap(&arr[l], &arr[l + ind]);
    int temp = arr[l], x = l, y = r;
    while (x < y) {
        while (x < y && arr[y] >= temp) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= temp) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = temp;
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);
}

int main() {
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    for (int i = 0; i < max_op; i++) arr[i] = rand() % 100;
    quick_sort(arr, 0, max_op - 1);
    for (int i = 0; i < max_op; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
