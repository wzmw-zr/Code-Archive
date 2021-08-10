/*************************************************************************
	> File Name: 5.LeetCode699.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月10日 星期二 22时42分28秒
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
    SegTree(int n) : n(n), nums(vector<int>(4 * n + 10, 0)), lazy(vector<int>(4 * n + 10, 0)) {}

    void push_down(int l, int r, int ind) {
        if (l == r) return ;
        nums[ind * 2 + 1] = max(nums[ind * 2 + 1], lazy[ind]);
        nums[ind * 2 + 2] = max(nums[ind * 2 + 2], lazy[ind]);
        lazy[ind * 2 + 1] = max(lazy[ind * 2 + 1], lazy[ind]);
        lazy[ind * 2 + 2] = max(lazy[ind * 2 + 2], lazy[ind]);
        lazy[ind] = 0;
    }

    int query(int s, int t, int l, int r, int ind) {
        if (t < l || s > r) return 0;
        if (l >= s && r <= t) return nums[ind];
        push_down(l, r, ind);
        int mid = (l + r) / 2;
        int ans = 0;
        if (s <= mid) ans = max(ans, query(s, t, l, mid, ind * 2 + 1));
        if (t > mid) ans = max(ans, query(s, t, mid + 1, r, ind * 2 + 2));
        return ans;
    }

    int query(int left, int right) {
        return query(left, right, 0, n, 0);
    }

    void push_up(int l, int r, int ind) {
        if (l == r) return ;
        nums[ind] = max(nums[ind * 2 + 1], nums[ind * 2 + 2]);
    }

    void update(int s, int t, int l, int r, int ind, int val) {
        if (t < l || s > r) return ;
        if (l >= s && r <= t) {
            nums[ind] = val;
            lazy[ind] = val;
            return ;
        }
        push_down(l, r, ind);
        int mid = (l + r) / 2;
        if (s <= mid) update(s, t, l, mid, ind * 2 + 1, val);
        if (t > mid) update(s, t, mid + 1 ,r, ind * 2 + 2, val);
        push_up(l, r, ind);
    }

    void update(int left, int right, int val) {
        update(left, right, 0, n, 0, val);
    }
};

vector<int> fallingSquares(vector<vector<int>>& positions) {
    set<int> points;
    for (auto p : positions) {
        points.insert(p[0]);
        points.insert(p[0] + p[1] - 1);
    }
    unordered_map<int, int> mp;
    int cnt = 0;
    for (int p : points) mp[p] = cnt++;
    SegTree seg(cnt);
    vector<int> ans;
    for (auto p : positions) {
        int left = mp[p[0]], right = mp[p[0] + p[1] - 1];
        int mmax = seg.query(left, right);
        seg.update(left, right, mmax + p[1]);
        ans.push_back(seg.nums[0]);
    }
    return ans;
}

int main() {
    return 0;
}
