/*************************************************************************
	> File Name: 2.LeetCode1622.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月13日 星期五 11时24分08秒
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

// TLE
const long MOD = 1e9 + 7;

using PII = pair<int, int>;

struct SegTree {
    int n;
    vector<long> nums;
    vector<queue<PII>> lazy;

    SegTree() = default;
    SegTree(int n) : n(n), nums(vector<long>(4 * n + 10, 0)), lazy(vector<queue<PII>>(4 * n + 10, queue<PII>())) {}

    void push_down(int ind, int l, int r) {
        if (l == r) return ;
        if (lazy[ind].empty()) return ;
        int mid = (l + r) / 2;
        while (!lazy[ind].empty()) {
            auto t = lazy[ind].front();
            lazy[ind].pop();
            if (!t.first) {
                nums[ind * 2 + 1] += 1L * t.second * (mid - l + 1);
                nums[ind * 2 + 2] += 1L * t.second * (r - mid);
            } else {
                nums[ind * 2 + 1] *= 1L * t.second;
                nums[ind * 2 + 2] *= 1L * t.second;
            }
            nums[ind * 2 + 1] %= MOD;
            nums[ind * 2 + 2] %= MOD;
            if (l != mid) lazy[ind * 2 + 1].push(t);
            if (r != (mid + 1)) lazy[ind * 2 + 2].push(t);
        }
    }

    void push_up(int ind, int l, int r) {
        if (l == r) return ;
        nums[ind] = (nums[ind * 2 + 1] + nums[ind * 2 + 2]) % MOD;
    }

    void add(int ind, int l, int r, int s, int t, int val) {
        if (l > t || r < s) return ;
        if (l >= s && r <= t) {
            nums[ind] += 1L * (r - l + 1) * val;
            nums[ind] %= MOD;
            if (l != r) lazy[ind].push(move(PII(0, val)));
            return ;
        }
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        if (s <= mid) add(ind * 2 + 1, l, mid, s, t, val);
        if (t > mid) add(ind * 2 + 2, mid + 1, r, s, t, val);
        push_up(ind, l, r);
    }

    void add(int left, int right, int val) {
        add(0, 0, n, left, right, val);
    }

    void mul(int ind, int l, int r, int s, int t, int val) {
        if (l > t || r < s) return ;
        if (l >= s && r <= t) {
            nums[ind] *= 1L * val;
            nums[ind] %= MOD;
            if (l != r) lazy[ind].push(move(PII(1, val)));
            return ;
        }
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        if (s <= mid) mul(ind * 2 + 1, l, mid, s, t, val);
        if (t > mid) mul(ind * 2 + 2, mid + 1, r, s, t, val);
        push_up(ind, l, r);
    }

    void mul(int left, int right, int val) {
        mul(0, 0, n, left, right, val);
    }

    int query(int ind, int l, int r, int s, int t) {
        if (l > t || r < s) return 0;
        if (l >= s && r <= t) return nums[ind];
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        long ans = 0;
        if (s <= mid) ans += 1L * query(ind * 2 + 1, l, mid, s, t);
        if (t > mid) ans += 1L * query(ind * 2 + 2, mid + 1, r, s, t);
        ans %= MOD;
        return ans;
    }

    int query(int left, int right) {
        return query(0, 0, n, left, right);
    }
};

class Fancy {
public:
    SegTree seg;
    int ind = -1;
    Fancy() : seg(SegTree(1e5 + 10)) {}

    void append(int val) {
        seg.add(ind + 1, ind + 1, val);
        ind++;
    }

    void addAll(int inc) {
        seg.add(0, ind, inc);
    }

    void multAll(int m) {
        seg.mul(0, ind, m);
    }

    int getIndex(int idx) {
        if (idx > ind) return -1;
        return seg.query(idx, idx);
    }
};

int main() {
    return 0;
}
