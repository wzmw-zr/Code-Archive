/*************************************************************************
	> File Name: 3.LineSegmentTree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月21日 星期三 11时02分12秒
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

#define MAX_N 100010

struct Node {
    int sum;
    int lazy_flag;
    Node() : sum(0), lazy_flag(0) {} 
    Node(int sum) : sum(sum), lazy_flag(0) {} 
};

int n;
Node t[4 * MAX_N + 10];
int nums[MAX_N + 5];

void build(int l, int r, int ind) {
    if (l > r) return ;
    if (l == r) {
        t[ind].sum = nums[ind];
        return ;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * ind);
    build(mid + 1, r, 2 * ind + 1);
    t[ind].sum = t[2 * ind].sum + t[2 * ind + 1].sum;
}

void update(int l, int r, int ll, int rr, int ind, int p) {
    if (l <= ll && rr <= r) {
        t[ind].sum += (rr - ll + 1) * p;
        t[ind].lazy_flag += p;
        return ;
    }
    int mid = (ll + rr) / 2;
    if (t[ind].lazy_flag && ll != rr) {
        t[2 * ind].sum += (mid - ll + 1) * p;
        t[2 * ind + 1].sum += (rr - mid) * p;
        t[2 * ind].lazy_flag += p;
        t[2 * ind + 1].lazy_flag += p;
    }
    if (l <= mid) update(l, r, ll, mid, 2 * ind, p);
    if (r > mid) update(l, r, mid + 1, rr, 2 * ind + 1, p);
    t[ind].sum += t[2 * ind].sum + t[2 * ind + 1].sum;
}

void all_update(int l, int r, int ll, int rr, int ind, int p) {
    if (l <= ll && rr <= r) {
        t[ind].sum = (rr - ll + 1) * p;
        t[ind].lazy_flag = p;
        return ;
    }
    int mid = (ll + rr) / 2;
    if (t[ind].lazy_flag && ll != rr) {
        t[2 * ind].sum = (mid - ll + 1) * t[ind].lazy_flag;
        t[2 * ind + 1].sum = (rr - mid) * t[ind].lazy_flag;
        t[2 * ind].lazy_flag = t[ind].lazy_flag;
        t[2 * ind + 1].lazy_flag = t[ind].lazy_flag;
        t[ind].lazy_flag = 0;
    } 
    if (l <= mid) all_update(l, r, ll, mid, 2 * ind, p);
    if (r > mid) all_update(l, r, mid + 1, rr, 2 * ind + 1, p);
    t[ind].sum += t[2 * ind].sum + t[2 * ind + 1].sum;
}

int all_query(int l, int r, int ll, int rr, int ind) {
    if (l <= ll && rr <= r) return t[ind].sum;
    int mid = (ll + rr) / 2;
    if (t[ind].lazy_flag && ll != rr) {
        t[2 * ind].sum = (mid - ll + 1) * t[ind].lazy_flag;
        t[2 * ind + 1].sum = (rr - mid) * t[ind].lazy_flag;
        t[2 * ind].lazy_flag = t[ind].lazy_flag;
        t[2 * ind + 1].lazy_flag = t[ind].lazy_flag;
        t[ind].lazy_flag = 0;
    }
    int sum = 0;
    if (l <= mid) sum += all_query(l, r, ll, mid, 2 * ind); 
    if (r > mid) sum += all_query(l, r, mid + 1, rr, 2 * ind + 1);
    return sum;
}

int query(int l, int r, int ll, int rr, int ind) {
    if (l <= ll && rr <= r) return t[ind].sum;
    int mid = (ll + rr) / 2;
    if (t[ind].lazy_flag && ll != rr) {
        t[2 * ind].sum += (mid - l + 1) * t[ind].lazy_flag;
        t[2 * ind + 1].sum += (rr - mid) * t[ind].lazy_flag;
        t[2 * ind].lazy_flag += t[ind].lazy_flag;
        t[2 * ind + 1].lazy_flag += t[ind].lazy_flag;
        t[ind].lazy_flag = 0;
    }
    int ans = 0;
    if (l <= mid) ans += query(l, r, ll, mid, 2 * ind);
    if (r > mid) ans += query(l, r, mid + 1, rr, 2 * ind + 1);
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    build(1, n, 1);
    return 0;
}
