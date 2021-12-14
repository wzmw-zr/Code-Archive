/*************************************************************************
	> File Name: 1.LeetCode630.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月14日 星期二 09时21分44秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

// WA
int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;
const static int MAX_N = 1e4 + 10;

struct SegTree {
    int val[MAX_N * 4 + 10];
    int lazy[MAX_N * 4 + 10];

    SegTree() = default;
    SegTree(int num) {
        memset(val, 0, sizeof(val));
        memset(lazy, 0, sizeof(lazy));
    }

    void push_down(int ind, int l, int r) {
        if (l == r) return ;
        lazy[ind * 2] = max(lazy[ind * 2], lazy[ind]);
        lazy[ind * 2 + 1] = max(lazy[ind * 2 + 1], lazy[ind]);
        val[ind * 2] = max(val[ind * 2], lazy[ind]);
        val[ind * 2 + 1] = max(val[ind * 2 + 1], lazy[ind]);
        lazy[ind] = 0;
    }

    void push_up(int ind, int l, int r) {
        if (l == r) return ;
        val[ind] = max(val[ind * 2], val[ind * 2 + 1]);
    }

    int query(int ind, int l, int r, int s, int t) {
        if (r < s || l > t) return 0;
        if (l >= s && r <= t) return val[ind];
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        int ans = 0;
        if (s <= mid) ans = max(ans, query(ind * 2, l, mid, s, t));
        if (t >= mid + 1) ans = max(ans, query(ind * 2 + 1, mid + 1, r, s, t));
        push_up(ind, l, r);
        return ans;
    }

    int query(int s, int t) {
        int ind = 1, l = 1, r = MAX_N;
        return query(ind, l, r, s, t);
    }

    void update(int ind, int l, int r, int s, int t, int num) {
        if (r < s || l > t) return ;
        if (l >= s && r <= t) {
            val[ind] = max(val[ind], num);
            lazy[ind] = max(lazy[ind], num);
            return ;
        }
        push_down(ind, l, r);
        int mid = (l + r) / 2;
        if (s <= mid) update(ind * 2, l, mid, s, t, num);
        if (t >= mid + 1) update(ind * 2 + 1, mid + 1, r, s, t, num);
        push_up(ind, l, r);
    }

    void update(int s, int t, int num) {
        int ind = 1, l = 1, r = MAX_N;
        update(ind, l, r, s, t, num);
    }

    int bs(int num) {
        int l = 1, r = MAX_N;
        while (l < r) {
            int mid = (l + r) / 2;
            if (query(mid, mid) >= num) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int scheduleCourse(vector<vector<int>>& courses) {
    vector<vector<int>> valids;
    for (auto &course : courses) {
        if (course[0] > course[1]) continue;
        valids.push_back(course);
    }
    auto cmp = [](vector<int> &a, vector<int> &b) {
        return a[1] - a[0] == b[1] - b[0] ? a[0] < b[0] : a[1] - a[0] < b[1] - b[0];
    };
    sort(valids.begin(), valids.end(), cmp);
    SegTree segtree(MAX_N);
    for (auto course : valids) {
        int mmax = segtree.query(1, course[1] - course[0] + 1);
        int ind = segtree.bs(mmax);
        segtree.update(ind + course[0], MAX_N, mmax + 1);
        // cout << "[" << course[0] << ", " << course[1] << "] mmax = " <<  mmax << ", ind = " << ind << ", all max = " << segtree.query(1, MAX_N) << endl;
    }
    return segtree.query(1, MAX_N);
}

int main() {
    return 0;
}
