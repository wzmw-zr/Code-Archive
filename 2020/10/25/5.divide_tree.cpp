/*************************************************************************
	> File Name: 5.divide_tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月25日 星期日 19时51分46秒
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
#define MAX_N 100000

int n;
int sorted[MAX_N + 10];
int tree[25][MAX_N + 10];
int to_left[25][MAX_N + 10];

void build_tree(int level, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    int same = mid - left + 1;
    for (int i = left; i <= right; i++) {
        if (tree[level][i] < sorted[mid]) same--;
    }
    int subLeft = left, subRight = mid + 1;
    for (int i = left; i <= right; i++) {
        to_left[level][i] = to_left[level][i - 1];
        if (tree[level][i] < sorted[mid] || (tree[level][i] == sorted[mid] && same > 0)) {
            tree[level + 1][subLeft++] = tree[level][i];
            to_left[level][i]++;
            if (tree[level][i] == sorted[mid]) same--;
        } else tree[level + 1][subRight++] = tree[level][i];
    }
    build_tree(level + 1, left, mid);
    build_tree(level + 1, mid + 1, right);
}

int query(int q_l, int q_r, int l, int r, int level, int k) {
    if (q_l == q_r) return tree[level][q_l];
    int mid = (l + r) / 2;
    int cnt = to_left[level][q_r] - to_left[level][q_l - 1];
    int x = to_left[level][q_l - 1] - to_left[level][l - 1];
    int y = to_left[level][q_r] - to_left[level][l - 1];
    int rx = q_r - l - y;
    int ry = q_l - l - x;
    if (cnt >= k) {
        int new_l = l + to_left[level][q_l - 1] - to_left[level][l - 1];
        int new_r = new_l + cnt - 1;
        return query(new_l, new_r, l, mid, level + 1, k);
    } 
    return query(mid + rx + 1, mid + ry + 1, mid + 1, r, level + 1, k - cnt);
}

int main() {
    return 0;
}
