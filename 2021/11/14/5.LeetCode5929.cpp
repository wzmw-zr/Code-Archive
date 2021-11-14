/*************************************************************************
	> File Name: 5.LeetCode5929.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月14日 星期日 11时23分24秒
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

using PII = pair<int, int>;

struct UnionSet {
    int n;
    vector<int> fa;

    UnionSet() = default;
    UnionSet(int n) : n(n), fa(vector<int>(n + 1)) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }

    int get(int x) {
        return x == fa[x] ? fa[x] : fa[x] = get(fa[x]);
    }

    bool merge(int x, int y, set<PII> &st) {
        int a = get(x);
        int b = get(y);
        if (a == b) return true;
        vector<int> nums1;
        vector<int> nums2;
        for (int i = 0; i < n; i++) {
            if (get(i) == a) nums1.push_back(i);
            if (get(i) == b) nums2.push_back(i);
        }
        for (auto p : nums1) {
            for (auto q : nums2) {
                if (st.count(PII(p, q))) return false;
            }
        }
        fa[a] = b;
        return true;
    }
};

vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
    int wzmw_zr_q4 = 0;
    UnionSet u(n);
    set<PII> st;
    for (auto r : restrictions) {
        st.insert(PII(r[0], r[1]));
        st.insert(PII(r[1], r[0]));
    }
    vector<bool> ans;
    for (auto r : requests) ans.push_back(u.merge(r[0], r[1], st));
    return ans;
}

int main() {
    return 0;
}
