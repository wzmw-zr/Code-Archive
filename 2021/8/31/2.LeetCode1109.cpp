/*************************************************************************
	> File Name: 2.LeetCode1109.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月31日 星期二 14时10分12秒
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
    vector<long> nums;
    vector<long> lazy;

    SegTree() = default;
    SegTree(int n) : n(n), nums(n * 4 + 10, 0), lazy(4 * n + 10, 0) {}

    void push_down(int ind, int l, int r) {
        if (l == r) return ;
        if (!lazy[ind]) return ;
        int mid = (l + r) / 2;
        nums[ind * 2 + 1] += 1L * (mid - l + 1) * lazy[ind];
        nums[ind * 2 + 2] += 1L * (r - mid) * lazy[ind];
        lazy[ind * 2 + 1] += lazy[ind];
        lazy[ind * 2 + 2] += lazy[ind];
        lazy[ind] = 0;
    }

    void push_up(int ind, int l, int r) {
        if (l == r) return ;
        nums[ind] = nums[ind * 2 + 1] + nums[ind * 2 + 2];
    }

    void update(int ind, int l, int r, int s, int t, int val) {
        if (l > t || r < s) return ;
        if (l >= s && r <= t) {
            nums[ind] += 1L * (r - l + 1) * val;
            lazy[ind] += 1L * val;
            return ;
        }
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        if (s <= mid) update(ind * 2 + 1, l, mid, s, t, val);
        if (t > mid) update(ind * 2 + 2, mid + 1, r, s, t, val);
        push_up(ind, l, r);
    }

    void update(int left, int right, int val) {
        update(0, 1, n, left, right, val);
    }

    int query(int ind, int l, int r, int s, int t) {
        if (l > t || r < s) return 0;
        if (l >= s && r <= t) return nums[ind];
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        int ans = 0;
        if (s <= mid) ans += query(ind * 2 + 1, l, mid, s, t);
        if (t > mid) ans += query(ind * 2 + 2, mid + 1, r, s, t);
        push_up(ind, l, r);
        return ans;
    }

    int query(int ind) {
        return query(0, 1, n, ind, ind);
    }
};

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    SegTree seg(n);
    for (auto x : bookings) seg.update(x[0], x[1], x[2]);
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) ans[i - 1] = seg.query(i);
    return ans;
}

int main() {
    return 0;
}
