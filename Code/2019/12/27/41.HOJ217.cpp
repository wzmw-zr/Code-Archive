/*************************************************************************
	> File Name: 41.HOJ217.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 22时05分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100000
using namespace std;

int score[max_n + 5] = {0};

int cmp(int a, int b) {
    return a >= b;
}

void solve(int n) {
    int mid;
    if (n * 1.0 / 2 - floor(n * 1.0 / 2) >= 0.5) mid = (int) ceil(n * 1.0 / 2);
    else mid = (int) floor(n * 1.0 / 2);
    int s, cnt = 0;
    for (int i = n; i >= mid; i--) {
        s = score[i];
        cnt++;
    } 
    for (int i = mid - 1; ; i--) {
        if (score[i] == score[i + 1]) cnt++;
        else break;
    }
    cout << s << " " << cnt;
}

void merge(int left, int mid, int right) {
    int a[right - left + 5] = {0};
    int count = 0;
    int index_1 = left, index_2 = mid + 1;
    while (index_1 <= mid && index_2 <= right) {
        while (score[index_1] <= score[index_2] && index_1 <= mid) a[count++] = score[index_1++];
        while (score[index_2] <= score[index_1] && index_2 <= right) a[count++] = score[index_2++];
    }
    if (index_1 <= mid) {
        while (index_1 <= mid) a[count++] = score[index_1++];
    }
    if (index_2 <= right) {
        while (index_2 <= right) a[count++] = score[index_2++];
    }
    for (int i = 0; i < count; i++) score[left + i] = a[i];
}

void merge_sort(int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);
    return ;
}

int main() {
    int n; 
    scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &score[i]);
    merge_sort(1, n);
    solve(n);
    return 0;
}
