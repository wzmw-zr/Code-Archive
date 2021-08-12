/*************************************************************************
	> File Name: 8.LeetCode850.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月12日 星期四 22时15分29秒
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

    void push_down(int ind, int l, int r) {
        if (l == r) return ;
        if (!lazy[ind]) return ;
        int mid = (l + r) / 2;
        nums[ind * 2 + 1] = (mid - l + 1) * lazy[ind];
        nums[ind * 2 + 2] = (r - mid) * lazy[ind];
        lazy[ind * 2 + 1] = lazy[ind];
        lazy[ind * 2 + 2] = lazy[ind];
        lazy[ind] = 0;
    }

    void push_up(int ind, int l, int r) {
        if (l == r) return ;
        nums[ind] = nums[ind * 2 + 1] + nums[ind * 2 + 2];
    }

    void update(int ind, int l, int r, int s, int t, int val) {
        if (l > t || r < s) return ;
        if (l >= s && r <= t) {
            nums[ind] = (r - l + 1) * val;
            lazy[ind] = val;
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
        if (s <= mid) ans += query(ind * 2 + 1, l, mid, s, t);
        if (t > mid) ans += query(ind * 2 + 2, mid + 1, r, s, t);
        return ans;
    }

    int query(int left, int right) {
        return query(0, 0, n, left, right);
    }
};

int rectangleArea(vector<vector<int>>& rectangles) {
    set<int> x_coords, y_coords;
    for (auto &rec : rectangles) {
        x_coords.insert(rec[0]);
        x_coords.insert(rec[2]);
        y_coords.insert(rec[1]);
        y_coords.insert(rec[3]);
    }
    int x_cnt = 0, y_cnt = 0;
    unordered_map<int, int> x_coord_to_ind, y_coord_to_ind;
    unordered_map<int, int> x_ind_to_coord, y_ind_to_coord;
    for (int x : x_coords) {
        x_coord_to_ind[x] = x_cnt;
        x_ind_to_coord[x_cnt++] = x;
    }
    for (int y : y_coords) {
        y_coord_to_ind[y] = y_cnt;
        y_ind_to_coord[y_cnt++] = y;
    }

    vector<SegTree> seg(x_cnt, SegTree(y_cnt));
    for (auto &rec : rectangles) {
        int x_1 = x_coord_to_ind[rec[0]], x_2 = x_coord_to_ind[rec[2]];
        int y_1 = y_coord_to_ind[rec[1]], y_2 = y_coord_to_ind[rec[3]];
        for (int i = x_1; i < x_2; i++) seg[i].update(y_1 + 1, y_2, 1);
    }

    const long MOD = 1e9 + 7;
    long ans = 0;
    
    for (int i = 1; i < x_cnt; i++) {
        int w = x_ind_to_coord[i]  - x_ind_to_coord[i - 1];
        int h = 0;
        for (int j = 1; j < y_cnt; j++) {
            if (seg[i - 1].query(j, j)) h += y_ind_to_coord[j] - y_ind_to_coord[j - 1];
        }
        ans += 1L * w * h;
        ans %= MOD;
    }

    return ans;
}

int main() {
    return 0;
}
