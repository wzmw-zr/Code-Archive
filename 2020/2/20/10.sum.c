/*************************************************************************
	> File Name: 10.sum.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月20日 星期四 22时28分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_n 500

typedef struct node {
    int ind, number;
} Node;

void merge(Node *arr, int l, int r) {
    int mid = (l + r) >> 1;
    int p1 = l, p2 = mid + 1, i = 0;
    Node temp[r - l + 1];
    while (p1 <= mid || p2 <= r) {
        if (p1 <= mid && (p2 > r || arr[p1].number < arr[p2].number)) temp[i++] = arr[p1++];
        else temp[i++] = arr[p2++];
    }
    memcpy(arr + l, temp, sizeof(Node) * (r - l + 1));
}

void merge_sort(Node *arr, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, r);
}

int find(Node *arr, int n, int val) {
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid].number == val) return mid;
        if (arr[mid].number < val) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

void solve(Node *arr, int n, int target) {
    for (int i = 1; i <= n; i++) {
        int ret = find(arr, n, target - arr[i].number);
        if (!ret) continue;
        printf("%d %d\n", arr[i].ind, arr[ret].ind);
        break;
    }
}

int main() {
    int n, num, target;
    Node number[max_n + 5];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        number[i].ind = i;
        number[i].number = num;
    } 
    scanf("%d", &target);
    merge_sort(number, 1, n);
    solve(number, n, target);
    return 0;
}
