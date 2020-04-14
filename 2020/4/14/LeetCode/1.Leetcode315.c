/*************************************************************************
	> File Name: 1.Leetcode315.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月14日 星期二 10时44分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_N 1000

void merge(int *num, int left, int right) {
    if (left == right) return ;
    int tmp[right - left + 1];
    int mid = (left + right) >> 1;
    int x = left, y = mid + 1, ind = 0;
    while (x <= mid || y <= right) {
        if (x <= mid && (y > right || num[x] < num[y])) tmp[ind++] = num[x++];
        else tmp[ind++] = num[y++];
    }
    memcpy(num + left, tmp, sizeof(int) * (right - left + 1));
}

void merge_sort(int *num, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    merge_sort(num, left, mid);
    merge_sort(num, mid + 1, right);
    merge(num, left, right);
}

int main() {
    srand(time(0));
    int n;
    int num[MAX_N + 5] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) num[i] = rand() % 10000;
    for (int i = 0; i < n; i++) printf("%d ", num[i]);
    printf("\n");
    merge_sort(num, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", num[i]);
    printf("\n");
    return 0;
}
