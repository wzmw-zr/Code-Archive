/*************************************************************************
	> File Name: 3.LeetCode1622.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月13日 星期五 16时12分50秒
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
const long MOD = 1e9 + 7;

struct SegTree {
    int n;
    vector<long> nums;
    vector<long> lazy_add;
    vector<long> lazy_mul;

    SegTree() = default;
    SegTree(int n) : n(n), nums(vector<long>(4 * n + 10, 0)), lazy_add(vector<long>(4 * n + 10, 0)), lazy_mul(vector<long>(4 * n + 10, 1)) {}

    void mul_push_down(int ind, int l, int r) {
        if (l == r) return ;
        int mid = (l + r) / 2;
        if (lazy_add[ind * 2 + 1]) add_push_down(ind * 2 + 1, l, mid);
        if (lazy_add[ind * 2 + 2]) add_push_down(ind * 2 + 2, mid + 1, r);
        if (lazy_mul[ind] == 1) return ;
        nums[ind * 2 + 1] = (nums[ind * 2 + 1] * lazy_mul[ind]) % MOD;
        nums[ind * 2 + 2] = (nums[ind * 2 + 2] * lazy_mul[ind]) % MOD;
        lazy_mul[ind * 2 + 1] = (nums[ind * 2 + 1] * lazy_mul[ind]) % MOD;
        lazy_mul[ind * 2 + 2] = (nums[ind * 2 + 2] * lazy_mul[ind]) % MOD;
        lazy_mul[ind] = 1;
    }

    void add_push_down(int ind, int l, int r) {
        if (l == r) return ;
        int mid = (l + r) / 2;
        if (lazy_mul[ind * 2 + 1] > 1) mul_push_down(ind * 2 + 1, l, mid);
        if (lazy_mul[ind * 2 + 2] > 1) mul_push_down(ind * 2 + 2, mid + 1, r);
        if (!lazy_add[ind]) return ;
        nums[ind * 2 + 1] = (nums[ind * 2 + 1] + 1L * (mid - l + 1) * lazy_add[ind]) % MOD;
        nums[ind * 2 + 2] = (nums[ind * 2 + 2] + 1L * (r - mid) * lazy_add[ind]) % MOD;
        lazy_add[ind * 2 + 1] = (lazy_add[ind * 2 + 1] + lazy_add[ind]) % MOD;
        lazy_add[ind * 2 + 2] = (lazy_add[ind * 2 + 2] + lazy_add[ind]) % MOD;
        lazy_add[ind] = 0;
    }

    void push_up(int ind, int l, int r) {
        if (l == r) return ;
        nums[ind] = (nums[ind * 2 + 1] + nums[ind * 2 + 2]) % MOD;
    }

    void add(int ind, int l, int r, int s, int t, int val) {
        if (l > t || r < s) return ;
        mul_push_down(ind, l, r);
        if (l >= s && r <= t) {
            nums[ind] = (nums[ind] + 1L * (r - l + 1) * val) % MOD;
            lazy_add[ind] = (lazy_add[ind] + 1L * val) % MOD;
            return ;
        }
        add_push_down(ind, l, r);
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
        add_push_down(ind, l, r);
        if (l >= s && r <= t) {
            nums[ind] = (nums[ind] * val) % MOD;
            lazy_mul[ind] = (lazy_mul[ind] * val) % MOD;
            return ;
        }
        mul_push_down(ind, l, r);
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
        add_push_down(ind, l, r);
        mul_push_down(ind, l, r);
        int mid = (l + r) / 2;
        long ans = 0;
        if (s <= mid) ans += query(ind * 2 + 1, l, mid, s, t);
        if (t > mid) ans += query(ind * 2 + 2, mid + 1, r, s, t);
        return ans % MOD;
    }

    int query(int left, int right) {
        return query(0, 0, n, left, right);
    }
};

class Fancy {
public:
    SegTree seg;
    int ind = -1;

    Fancy() : seg(SegTree(1e5)) {}

    void append(int val) {
        ind++;
        seg.add(ind, ind, val);
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
