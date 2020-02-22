/*************************************************************************
	> File Name: 8.binary.search.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 20时33分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define P(func, args...) {\
    printf("%s = %d\n", #func, func(args));\
}

int binary_search1(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int binary_search2(int *arr, int n) {
    int head = -1, tail = n - 1, mid; 
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (arr[mid]) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int binary_search3(int *arr, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid]) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    srand(time(0));
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int arr2[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    P(binary_search1, arr1, 10, 7);
    P(binary_search2, arr2, 10);
    P(binary_search3, arr3, 10);
    return 0;
}
