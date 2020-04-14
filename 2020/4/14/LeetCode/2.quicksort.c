/*************************************************************************
	> File Name: 3.LeetCode324.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月14日 星期二 15时23分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_N 1000

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *nums, int left, int right) {
    printf("left = %d, right = %d\n", left, right);
    if (left >= right) return ;
    int offset = rand() % (right - left + 1);
    swap(&nums[left], &nums[left + offset]);
    int tmp = nums[left];
    int x = left, y = right;
    while (x < y) {
        while (x < y && nums[y] >= tmp) y--;
        if (x < y) nums[x++] = nums[y];
        while (x < y && nums[x] <= tmp) x++;
        if (x < y) nums[y--] = nums[x];
    }
    nums[x] = tmp;
    quick_sort(nums, left, x - 1);
    quick_sort(nums, x + 1, right);
}

int main() {
    srand(time(0));
    int n;
    int nums[MAX_N + 5] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) nums[i] = rand() % 10000;
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");
    quick_sort(nums, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
