/*************************************************************************
	> File Name: 2.LeetCode5899.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月30日 星期六 22时35分05秒
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

struct BIT {
    vector<int> nums;
    int cnt;

    BIT() = default;
    BIT(int cnt) : nums(vector<int>(cnt + 10, 0)), cnt(cnt) {}

    int lowbit(int x) { return x & (-x); };

    void update(int ind, int val) {
        while (ind <= cnt) {
            nums[ind] = max(nums[ind], val);
            ind += lowbit(ind);
        }
    }

    int query(int ind) {
        int ans = 0;
        while (ind) {
            ans = max(nums[ind], ans);
            ind -= lowbit(ind);
        }
        return ans;
    }
};

int maxTwoEvents(vector<vector<int>>& events) {
    int wzmw_zr_q2 = 0;
    set<int> st;
    for (auto x : events) {
        st.insert(x[0]);
        st.insert(x[1]);
    }
    int ind = 1;
    unordered_map<int, int> mp;
    for (int x : st) mp[x] = ind++;
    auto cmp = [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; };
    sort(events.begin(), events.end(), cmp);
    BIT bit(ind + 10);
    for (auto x : events) bit.update(mp[x[1]], x[2]);
    int ans = 0;
    for (auto x : events) ans = max(ans, x[2] + bit.query(mp[x[0]] - 1));
    return ans;
}

int main() {
    return 0;
}
