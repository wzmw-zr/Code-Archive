/*************************************************************************
	> File Name: 43.HOJ219.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 23时13分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10000
using namespace std;

int num[max_n + 5] = {0};

void merge(int left, int mid, int right) {
    int temp[right - left + 1];
    int index_1 = left, index_2 = mid + 1, count = 0;
    while (index_1 <= mid && index_2 <= right) {
        while (num[index_1] <= num[index_2] && index_1 <= mid && index_2 <= right) temp[count++] = num[index_1++];
        while (num[index_2] <= num[index_1] && index_2 <= right && index_1 <= mid) temp[count++] = num[index_2++];
    }
    while (index_1 <= mid) temp[count++] = num[index_1++];
    while (index_2 <= right) temp[count++] = num[index_2++];
    for (int i = 0; i < count; i++) num[left + i] = temp[i];
}

void merge_sort(int left, int right) {
    if (left == right) return ;
    int mid = (left + mid) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);
}


void re_merge(int left, int mid, int right) {
    int temp[right - left + 1];
    int index_1 = left, index_2 = mid + 1, count = 0;
    while (index_1 <= mid && index_2 <= right) {
        while (num[index_1] >= num[index_2] && index_1 <= mid) temp[count++] = num[index_1++];
        while (num[index_2] >= num[index_1] && index_2 <= right) temp[count++] = num[index_2++];
    }
    while (index_1 <= mid) temp[count++] = num[index_1++];
    while (index_2 <= right) temp[count++] = num[index_2++];
    for (int i = 0; i < count; i++) num[left + i] = temp[i];
}

void reverse_merge_sort(int left, int right) {
    if (left == right) return ;
    int mid = (left + mid) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    re_merge(left, mid, right);
}

int main() {
    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 1; i <= n; i++) cin >> num[i];
    merge_sort(l1, r1);
    //reverse_merge_sort(l2, r2);
    for (int i = 1; i <= n; i++) {
        i == n && cout << num[i];
        i != n && cout << num[i] << " ";
    }
    return 0;
}
