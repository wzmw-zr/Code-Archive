/*************************************************************************
	> File Name: 9.say.number.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 22时06分07秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 100000

void merge(int *arr, int l, int r) {
    int mid = (l + r) >> 1, temp[r - l + 1];
    int p1 = l, p2 = mid + 1, i = 0;
    while (p1 <= mid || p2 <= r) {
        if (p1 <= mid && (p2 > r || arr[p1] < arr[p2])) temp[i++] = arr[p1++];
        else temp[i++] = arr[p2++];
    }
    memcpy(arr + l, temp, sizeof(int) * (r - l + 1));
}

void merge_sort(int *arr, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, r);
}

int getnumber(int *arr, int num, int n) {
    int l = -1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (arr[mid] == num) return arr[mid];
        if (arr[mid] < num) l = mid;
        else r = mid - 1;
    }
    return l == -1 ? arr[0] : arr[l];
}

int main() {
    int n, m, a[max_n + 5], num;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        i && printf(" ");
        printf("%d", getnumber(a, num, n));
    }
    printf("\n");
    return 0;
}
