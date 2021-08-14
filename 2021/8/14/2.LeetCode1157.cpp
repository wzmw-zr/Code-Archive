/*************************************************************************
	> File Name: 2.LeetCode1157.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月14日 星期六 16时07分22秒
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

// WA, misunderstanding the meaning of problem.
using PII = pair<int, int>;

struct SegTree {
    int n;
    vector<PII> vals;
    vector<int> lazy;

    SegTree() = default;
    SegTree(int n) : n(n), vals(vector<PII>(4 * n + 10, PII(0, 0))), lazy(vector<int>(4 * n + 10, 0)) {
        build(0, 0, n);
    }

    void build(int ind, int l, int r) {
        if (l == r) {
            vals[ind] = PII(l, 0);
            return ;
        }
        int mid = (l + r) / 2;
        build(2 * ind + 1, l, mid);
        build(2 * ind + 2, mid + 1, r);
        push_up(ind, l, r);
    }

    void push_down(int ind, int l, int r) {
        if (l == r) return ;
        if (!lazy[ind]) return ;
        vals[ind * 2 + 1].second += lazy[ind];
        vals[ind * 2 + 2].second += lazy[ind];
        lazy[ind * 2 + 1] += lazy[ind];
        lazy[ind * 2 + 2] += lazy[ind];
        lazy[ind] = 0;
    }

    void push_up(int ind, int l, int r) {
        if (l == r) return ;
        if (vals[2 * ind + 1].second >= vals[2 * ind + 2].second) vals[ind] = vals[2 * ind + 1];
        else vals[ind] = vals[2 * ind + 2];
    }

    void update(int ind, int l, int r, int s, int t, int val) {
        if (l > t || r < s) return ;
        if (l >= s && r <= t) {
            vals[ind].second += val;
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

    PII query(int ind, int l, int r, int s, int t) {
        if (l > t || r < s) return PII(0, 0);
        if (l >= s && r <= t) return vals[ind];
        PII ans(0, 0);
        int mid = (l + r) / 2;
        if (s <= mid) {
            PII temp = query(ind * 2 + 1, l, mid, s, t);
            if (temp.second > ans.second) ans = temp;
        }
        if (t > mid) {
            PII temp = query(ind * 2 + 2, mid + 1, r, s, t);
            if (temp.second > ans.second) ans = temp;
        }
        return ans;
    }

    PII query(int left, int right) {
        return query(0, 0, n, left, right);
    }
};

class MajorityChecker {
public:
    SegTree seg;
    MajorityChecker(vector<int>& arr) : seg(SegTree(20000)){
        for (int x : arr) seg.update(x, x, 1);
    }

    int query(int left, int right, int threshold) {
        auto &&[val, cnt] = seg.query(left, right);
        if (cnt >= threshold) return val;
        return -1;
    }
};

int main() {
    return 0;
}
