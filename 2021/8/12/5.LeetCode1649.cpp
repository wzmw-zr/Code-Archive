/*************************************************************************
	> File Name: 5.LeetCode1649.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月12日 星期四 16时04分14秒
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
    SegTree(int n) : n(n), nums(vector<int>(4 * n + 10)), lazy(vector<int>(4 * n + 10, 0)) {}

    void push_down(int ind, int l, int r) {
        if (l == r) return ;
        if (!lazy[ind]) return ;
        int mid = (l + r) / 2;
        nums[ind * 2 + 1] += (mid - l + 1) * lazy[ind];
        nums[ind * 2 + 2] += (r - mid) * lazy[ind];
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
        if (l >= s && r <= s) {
            nums[ind] += val * (r - l) + 1;
            lazy[ind] += val;
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


int createSortedArray(vector<int>& instructions) {
    const long MOD = 1e9 + 7;
    long ans = 0;
    SegTree seg(1e5 + 1);
    for (int x : instructions) {
        ans += 1L * min(seg.query(0, x - 1), seg.query(x + 1, 1e5 + 1));
        ans %= MOD;
        seg.update(x, x, 1);
    }
    return ans;
}

int main() {
    int n;
    vector<int> instructions;
    while (cin >> n) instructions.push_back(n);
    cout << createSortedArray(instructions) << endl;
    return 0;
}
