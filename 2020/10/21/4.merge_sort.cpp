/*************************************************************************
	> File Name: 4.merge_sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月21日 星期三 11时45分58秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
#define MAX_N 100010

int n;
int nums[MAX_N + 10];

void merge(int *arr, int l, int r) {
    int temp[r - l + 1];
    memset(temp, 0, sizeof(temp));
    int mid = (l + r) / 2;
    int x = l, y = mid + 1, ind = 0;
    while (x <= mid || y <= r) {
        if (x <= mid && (y > r || arr[x] <= arr[y])) temp[ind++] = arr[x++];
        else temp[ind++] = arr[y++];
    }
    memcpy(arr + l, temp, sizeof(temp));
}

void merge_sort(int *arr, int l, int r) {
    if (l >= r) return ;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, r);
}

int main() {
    srand(time(0));
    cin >> n;
    for (int i = 0; i < n; i++) nums[i] = rand() % 1000000;
    merge_sort(nums, 0, n - 1);
    return 0;
}
