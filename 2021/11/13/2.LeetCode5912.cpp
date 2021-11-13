/*************************************************************************
	> File Name: 2.LeetCode5912.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月13日 星期六 22时35分48秒
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

const int MAX_N = 1e5 + 10;

struct BIT {
    int n;
    vector<int> nums;

    BIT() = default;
    BIT(int n) : n(n), nums(vector<int>(n + 1, 0)) {}

    int lowbit(int x) { return x & -x; }

    void update(int ind, int val) {
        while (ind <= n) {
            nums[ind] = max(nums[ind], val);
            ind += lowbit(ind);
        }
    }

    int query(int ind) {
        int ans = 0;
        while (ind) {
            ans = max(ans, nums[ind]);
            ind -= lowbit(ind);
        }
        return ans;
    }
};

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    int wzmw_zr_q3 = 0;
    set<int> st;
    for (auto item : items) st.insert(item[0]);
    for (auto q : queries) st.insert(q);
    int ind = 0;
    unordered_map<int, int> mp;
    for (int x : st) mp[x] = ++ind;
    BIT bit(ind);
    for (auto item : items) bit.update(mp[item[0]], item[1]);
    int q = queries.size();
    vector<int> ans(q);
    for (int i = 0; i < q; i++) ans[i] = bit.query(mp[queries[i]]);
    return ans;
}

int main() {
    return 0;
}
