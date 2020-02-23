/*************************************************************************
	> File Name: 6.88.merge.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月23日 星期日 14时37分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *temp = (int *) malloc(sizeof(int) * (m + n));
    int p1 = 0, p2 = 0, i = 0;
    while (p1 < m || p2 < n) {
        if (p1 < m && (p2 >= n || nums1[p1] < nums2[p2])) temp[i++] = nums1[p1++];
        else temp[i++] = nums2[p2++];
    }
    printf("temp = [");
    for (int i = 0;  i < m + n; i++) printf("%d ", temp[i]);
    printf("]\n");
    memcpy(nums1, temp, sizeof(int) * (m + n));
    printf("nums1 = [");
    for (int i = 0;  i < m + n; i++) printf("%d ", nums1[i]);
    printf("]\n");
    free(temp);
}

int main() {
    srand(time(0));
    int n, m;
    scanf("%d%d", &n, &m);
    int arr1[2 * n] = {0}, arr2[m] = {0};
    for (int i = 0; i < n; i++) arr1[i] = rand() % 100;
    for (int i = 0; i < m; i++) arr2[i] = rand() % 100;
    for (int i = 0; i < n; i++) printf("%d ", arr1[i]);
    printf("\n");
    for (int i = 0; i < m; i++) printf("%d ", arr2[i]);
    printf("\n");
    merge(arr1, 2 * n, n, arr2, m, m);
    for (int i = 0; arr1[i]; i++) printf("%d ", arr1[i]);
    printf("\n");
    return 0;
}
