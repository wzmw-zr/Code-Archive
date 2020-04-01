/*************************************************************************
	> File Name: 2.merge.sort.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月28日 星期六 09时44分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define NUM 1000

int number[NUM];

void merge(int left, int right) {
    int mid = (left + right) >> 1, x = left, y = mid + 1, ind = 0;
    int temp[right - left + 1];
    while (ind <= right - left) {
        if (x <= mid && (y > right || number[x] <= number[y])) temp[ind++] = number[x++];
        else temp[ind++] = number[y++];
    }
    memcpy(number + left, temp, sizeof(temp));
}

void merge_sort(int left, int right) {
    if (left == right) return;
    int mid = (left + right) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, right);
}

int main() {
    srand(time(0));    
    for (int i = 0; i < NUM; i++) number[i] = rand() % 10000;
    for (int i = 0; i < NUM; i++) printf("%d ", number[i]);
    printf("\n");
    merge_sort(0, NUM - 1);
    for (int i = 0; i < NUM; i++) printf("%d ", number[i]);
    printf("\n");
    return 0;
}
