/*************************************************************************
	> File Name: 3.LeetCode5861.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月18日 星期六 22时46分30秒
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
    vector<long> val;
    vector<long> lazy;

    SegTree() = default;
    SegTree(int n) : n(n), val(4 * n + 10, 0), lazy(4 * n + 10, 0) {}

    void push_down(int ind, int l, int r) {
        if (l == r) return ;
        val[ind * 2 + 1] = max(val[ind * 2 + 1], lazy[ind]);
        val[ind * 2 + 2] = max(val[ind * 2 + 2], lazy[ind]);
        lazy[ind * 2 + 1] = max(lazy[ind * 2 + 1], lazy[ind]);
        lazy[ind * 2 + 2] = max(lazy[ind * 2 + 2], lazy[ind]);
        lazy[ind] = 0;
    }

    void push_up(int ind, int l, int r) {
        if (l == r) return ;
        val[ind] = max(val[ind * 2 + 1], val[ind * 2 + 2]);
    }

    long query(int ind, int l, int r, int s, int t) {
        printf("l = %d, r = %d, s = %d, t = %d\n", l, r, s, t);
        if (l > t || r < s) return 0;
        if (l >= s && r <= t) return val[ind];
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        long ans = 0;
        if (s <= mid) ans = max(ans, query(ind * 2 + 1, l, mid, s, t));
        if (t > mid) ans = max(ans, query(ind * 2 + 2, mid + 1, r, s, t));
        push_up(ind, l, r);
        return ans;
    }

    long query(int ind) {
        return query(0, 1, n, ind, ind);
    }

    void update(int ind, int l, int r, int s, int t, long num) {
        if (l > t || r < s) return ;
        if (l >= s && r <= t) {
            val[ind] = max(val[ind], num);
            lazy[ind] = max(lazy[ind], num);
            return ;
        }
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        if (s <= mid) update(ind * 2 + 1, l, mid, s, t, num);
        if (t > mid) update(ind * 2 + 2, mid + 1, r, s, t, num);
        push_up(ind, l, r);
    }

    void update(int left, int right, long num) {
        update(0, 1, n, left, right, num);
    }
};

long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end());
    SegTree segtree(n);
    for (auto &&r : rides) {
        long t = segtree.query(r[0]);
        segtree.update(r[1], n, t + r[1] - r[0] + r[2]);
        for (int i = 1; i <= n; i++) cout << segtree.query(i) << " ";
        cout << endl << endl;
    }
    return segtree.query(n);
}

int main() {
    return 0;
}
