/*************************************************************************
	> File Name: 1.leetcode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月23日 星期日 07时58分20秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int ind, value;
} Node;

Node *NewNode(int ind, int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->ind = ind;
    node->value = val;
    return node;
}

void init(Node **node, int *nums, int size) {
    for (int i = 0; i < size; i++) node[i] = NewNode(i, nums[i]);
}

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}


void merge(Node **node, int l, int r) {
    Node *temp[r - l + 1];
    int mid = (l + r) >> 1;
    int x = l, y = mid + 1, i = 0;
    while (x <= mid || y <= r) {
        if (x <= mid && (y > r || node[x]->value < node[y]->value)) temp[i++] = node[x++];
        else temp[i++] = node[y++];
    }
    memcpy(node + l, temp, sizeof(Node *) * (r - l + 1));
}

void sort_node(Node **node, int l, int r) {
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    sort_node(node, l, mid);
    sort_node(node, mid + 1, r);
    merge(node, l, r);
}

int find(Node **node, int num, int numsSize) {
    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (node[mid]->value == num) return node[mid]->ind; 
        if (node[mid]->value < num) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Node *num[numsSize]; 
    init(num, nums, numsSize);
    sort_node(num, 0, numsSize - 1);
    int *ret = (int *) malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        int ind = find(num, target, numsSize);
        if (ind == -1) continue;
        if (ind < i) swap(ind, i);
        ret[0] = i;
        ret[1] = ind;
        break;
    }
    return ret;
}

int main() {
    return 0;
}
