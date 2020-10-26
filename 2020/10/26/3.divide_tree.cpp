/*************************************************************************
	> File Name: 3.divide_tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月26日 星期一 10时03分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAX_N 10000

int n;
int a[MAX_N + 10], sorted[MAX_N + 10];
int tree[20][MAX_N + 10], to_left[20][MAX_N + 10];

void build(int level, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    int x = l, y = mid + 1, same = mid - l + 1;
    int num = sorted[mid];
    for (int i = l; i <= mid; i++) {
        if (tree[level][i] < num) same--;
    }
    for (int i = l; i <= r; i++) {
        to_left[level][i] = (i == l ? 0 : to_left[level][i - 1]);
        if (tree[level][i] < num || (tree[level][i] == num && same)) {
            tree[level + 1][x++] = tree[level][i];
            if (tree[level][i] == num) same--;
            to_left[level][i]++;
        } else 
            tree[level + 1][y++] = tree[level][i];
    }
    build(level + 1, l, mid);
    build(level + 1, mid + 1, r);
}

int query(int level, int x, int y, int l, int r, int k) {
    if (x == y) return tree[level][x];
    int cnt = to_left[level][y] - (x == l ? 0 : to_left[level][x - 1]);
    int mid = (l + r) >> 1;
    if (cnt >= k) {
        int st = l + (x == l ? 0 : to_left[level][x - 1]);
        int ed = l + to_left[level][y] - 1;
        return query(level + 1, st, end, l, mid, k);
    } else {
        int st = mid + 1 + x - l - (x == l ? 0 : to_left[level][x - 1]);
        int ed = mid + 1 + y - l - to_left[level][y];
        return query(level + 1, st, end, mid + 1, r, k - cnt);
    }
}

int main() {
    return 0;
}
