/*************************************************************************
	> File Name: 2.binary_search.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月19日 星期三 19时15分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int binary1(int *arr, int len, int val) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) >> 1; 
        if (arr[mid] == val) return mid;
        if (arr[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int binary2(int *arr, int len) {
    int l = 0, r = len, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (arr[mid]) r = mid;
        else l = ++mid;
    }
    return (mid == len ? -1 : mid);
}

int binary3(int *arr, int len) {
    int l = -1, r = len - 1, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (arr[mid]) l = mid;
        else r = --mid;
    }
    return mid;
}

int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int arr3[10] = {1, 1, 1, 1, 1, 0, 0 , 0, 0, 0};
    printf("%d\n", binary1(arr1, 10, 7));
    printf("%d\n", binary2(arr2, 10));
    printf("%d\n", binary3(arr3, 10));
    return 0;
}
