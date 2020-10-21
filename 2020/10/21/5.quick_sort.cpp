/*************************************************************************
	> File Name: 5.quick_sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月21日 星期三 11时52分32秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
#define MAX_N 100010

int n;
int nums[MAX_N + 5];

void quick_sort(int *arr, int l, int r) {
    if (l >= r) return ;
    int ind = rand() % (r - l + 1);
    swap(arr[l], arr[l + ind]);
    int x = l, y = r, num = arr[l];
    while (x < y) {
        while (x < y && arr[y] >= num) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= num) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = num;
    quick_sort(arr, l, x - 1);
    quick_sort(arr, x + 1, r);
}

int main() {
    srand(time(0));
    cin >> n;
    for (int i = 0; i < n; i++) nums[i] = rand() % 1000000;
    quick_sort(nums, 0, n - 1);
    return 0;
}
