/*************************************************************************
	> File Name: 2.LeetCode683.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月10日 星期二 10时01分36秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


struct SegTree {
    int n;
    vector<int> nums;
    vector<int> lazy;

    SegTree() = default;
    SegTree(int n) : n(n), nums(vector<int>(n * 4 + 10, 0)), lazy(vector<int>(n * 4 + 10, 0)) {}

    void push_down(int l, int r, int ind) {
        if (l == r) return ;
        int mid = (l + r) / 2;
        nums[ind * 2 + 1] += (mid - l + 1) * lazy[ind];
        nums[ind * 2 + 2] += (r - mid) * lazy[ind];
        lazy[ind * 2 + 1] += lazy[ind];
        lazy[ind * 2 + 2] += lazy[ind];
        lazy[ind] = 0;
    }

    void update(int s, int t, int l, int r, int ind, int val) {
        if (t < l || s > r) return ;
        if (l >= s && r <= t) {
            nums[ind] += (r - l + 1) * val;
            lazy[ind] += val;
            return ;
        }
        push_down(l, r, ind);
        int mid = (l + r) / 2;
        if (s <= mid) update(s, t, l, mid, ind * 2 + 1, val);
        if (t > mid) update(s, t, mid + 1, r, ind * 2 + 2, val);
        nums[ind] = nums[ind * 2 + 1] + nums[ind * 2 + 2];
        return ;
    }

    void update(int l, int r, int val) {
        update(l, r, 1, n, 0, val);
    }

    int query(int s, int t, int l, int r, int ind) {
        if (t < l || s > r) return 0;
        if (l >= s && r <= t) return nums[ind];
        push_down(l, r, ind);
        int mid = (l + r) / 2;
        int ans = 0;
        if (s <= mid) ans += query(s, t, l, mid, ind * 2 + 1);
        if (t > mid) ans += query(s, t, mid + 1, r, ind * 2 + 2);
        return ans;
    }

    int query(int l, int r) {
        return query(l, r, 1, n, 0);
    }
};


int kEmptySlots(vector<int>& bulbs, int k) {
    int n = bulbs.size();
    SegTree seg(n);
    for (int i = 0; i < n; i++) {
        seg.update(bulbs[i], bulbs[i], 1);
        if ((bulbs[i] >= (k + 2)) && (seg.query(bulbs[i] - k - 1, bulbs[i]) == 2) && (seg.query(bulbs[i] - k, bulbs[i]) == 1)) return i + 1;
        if ((bulbs[i] <= (n - k - 1)) && (seg.query(bulbs[i], bulbs[i] + k + 1) == 2) && (seg.query(bulbs[i], bulbs[i] + k) == 1)) return i + 1;
    }
    return -1;
}

int main() {
    return 0;
}
