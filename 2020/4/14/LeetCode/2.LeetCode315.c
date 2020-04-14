/*************************************************************************
	> File Name: 2.LeetCode.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月14日 星期二 11时18分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_N 1000

typedef struct Node {
    int ind, val, cnt;
} Node;

void merge(Node *nums, int left, int right) {
    if (left == right) return ;
    Node tmp[right - left + 1];
    int mid = (left + right) >> 1;
    int x = left, y = mid + 1, ind = 0;
    while (x <= mid || y <= right) {
        if (x <= mid && (y > right || nums[x].val < nums[y].val)) tmp[ind++] = nums[x++];
        else {
            for (int i = x; i <= mid; i++) nums[i].cnt++;
            tmp[ind++] = nums[y++];
        }
    }
    memcpy(nums + left, tmp, sizeof(Node) * (right - left + 1));
}

void merge_sort_and_count(Node *nums, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    merge_sort_and_count(nums, left, mid);
    merge_sort_and_count(nums, mid + 1, right);
    merge(nums, left, right);
}

int* countSmaller(Node* nums, int numsSize, int* returnSize){
    int *cnt = (int *) calloc(sizeof(int), numsSize);
    *returnSize = numsSize;
    merge_sort_and_count(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i].ind] = nums[i].cnt;
    }
    return cnt;
}

int main() {
    srand(time(0));
    int n;
    Node *nums = (Node *) calloc(sizeof(Node), MAX_N);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        nums[i].ind = i;
        //nums[i].val = rand() % 10000;
        scanf("%d", &nums[i].val);
    }
    int number;
    int *ret = countSmaller(nums, n, &number);
    for (int i = 0; i < n; i++) printf("%d ", ret[i]);
    printf("\n");
    return 0;
}
