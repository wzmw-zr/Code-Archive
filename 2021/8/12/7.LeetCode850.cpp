/*************************************************************************
	> File Name: 7.LeetCode850.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月12日 星期四 18时27分30秒
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

// WA
struct SegTree {
    int n;
    vector<int> nums;
    vector<int> lazy;

    SegTree() = default;
    SegTree(int n) : n(n), nums(vector<int>(4 * n + 10, 0)), lazy(vector<int>(4 * n + 10, 0)) {}

    void push_down(int ind, int l, int r) {
        if (l == r) return ;
        if (!lazy[ind]) return ;
        nums[ind * 2 + 1] = max(nums[ind * 2 + 1], lazy[ind]);
        nums[ind * 2 + 2] = max(nums[ind * 2 + 2], lazy[ind]);
        lazy[ind * 2 + 1] = max(lazy[ind * 2 + 1], lazy[ind]);
        lazy[ind * 2 + 2] = max(lazy[ind * 2 + 1], lazy[ind]);
        lazy[ind] = 0;
    }

    void push_up(int ind, int l, int r) {
        if (l == r) return ;
        nums[ind] = max(nums[ind * 2 + 1], nums[ind * 2 + 2]);
    }

    void update(int ind, int l, int r, int s, int t, int val) {
        if (l > t || r < s) return ;
        if (l >= s && r <= t) {
            nums[ind] = max(nums[ind], val);
            lazy[ind] = max(lazy[ind], val);
            return ;
        }
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        if (s <= mid) update(ind * 2 + 1, l, mid, s, t, val);
        if (t > mid) update(ind * 2 + 2, mid + 1, r, s, t, val);
        push_up(ind, l, r);
    }

    void update(int left, int right, int val) {
        update(0, 0, n, left, right, val);
    }

    int query(int ind, int l, int r, int s, int t) {
        if (l > t || r < s) return 0;
        if (l >= s && r <= t) return nums[ind];
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        int ans = 0;
        if (s <= mid) ans = max(ans, query(ind * 2 + 1, l, mid, s, t));
        if (t > mid) ans = max(ans, query(ind * 2 + 2, mid + 1, r, s, t));
        return ans;
    }

    int query(int ind) {
        return query(0, 0, n, ind, ind);
    }
};

int rectangleArea(vector<vector<int>>& rectangles) {
    set<int> st;
    for (auto rec : rectangles) {
        st.insert(rec[0]);
        st.insert(rec[2]);
    }
    int cnt = 0;
    unordered_map<int, int> coord_to_ind;
    unordered_map<int, int> ind_to_coord;
    for (int x : st) {
        coord_to_ind[x] = cnt;
        ind_to_coord[cnt++] = x;
    }
    SegTree seg(cnt);
    for (auto rec : rectangles) seg.update(coord_to_ind[rec[0]], coord_to_ind[rec[2]], rec[3]);
    const long MOD = 1e9 + 7;
    long ans = 0;
    for (int i = 1; i < cnt; i++) {
        int h = min(seg.query(i - 1), seg.query(i));
        ans += 1L * h * (ind_to_coord[i] - ind_to_coord[i - 1]);
        ans %= MOD;
    }
    return ans;
}

int main() {
    return 0;
}
