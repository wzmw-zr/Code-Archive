/*************************************************************************
	> File Name: 8.349.intersectioon.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月23日 星期日 18时16分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void output(int *num, int size) {
    printf("num = [");
    for (int i = 0; i < size; i++) printf("%d ", num[i]);
    printf("]\n");
}

void merge(int *num, int l, int r) {
    int mid = (l + r) >> 1, temp[r - l + 1];
    int x = l, y = mid + 1, i = 0;
    while (x <= mid || y <= r) {
        if (x <= mid && (y > r || num[x] < num[y])) temp[i++] = num[x++];
        else temp[i++] = num[y++];
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
}

void merge_sort(int *num, int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid); 
    merge_sort(num, mid + 1, r);
    merge(num, l, r);
}

int find(int *num, int target, int size) {
    int l = 0, r = size - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (num[mid] == target) return 1;
        if (num[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *temp = (int *) malloc(sizeof(int) * (nums1Size + nums2Size));
    merge_sort(nums1, 0, nums1Size - 1);
    merge_sort(nums2, 0, nums2Size - 1);
    int p1 = 0, p2 = 0;
    *returnSize = 0;
    while (p1 < nums1Size && p2 < nums2Size) {
        if (nums1[p1] == nums2[p2]) {
            temp[(*returnSize)++] = nums1[p1];
            p1++, p2++;
        } else if (nums1[p1] < nums2[p2]) p1++;
        else p2++;
    }
    output(temp, *returnSize);
    return temp;
}

int main() {
    int n, m, returnSize, *ret;
    scanf("%d%d", &n, &m);
    int num1[n], num2[m];
    for (int i = 0; i < n; i++) scanf("%d", &num1[i]);
    for (int i = 0; i < m; i++) scanf("%d", &num2[i]);
    ret = intersection(num1, n, num2, m, &returnSize);
    for (int i = 0; i < returnSize; i++) printf("%d ", ret[i]);
    printf("\n");
    return 0;
}
