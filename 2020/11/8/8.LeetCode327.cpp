/*************************************************************************
	> File Name: 8.LeetCode327.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月08日 星期日 16时31分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct BIT {
    int n;
    vector<int> tree;

    BIT() = default;
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x) { return x & -x; }

    void add(int ind, int d) {
        while (ind <= n) {
            tree[ind] += d;
            ind += lowbit(ind);
        }
    }

    int query(int ind) {
        int ans = 0;
        while (ind) {
            ans += tree[ind];
            ind -= lowbit(ind);
        }
        return ans;
    }

};

int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long> preSum(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) preSum[i + 1] += preSum[i] + nums[i];
    set<long> st;
    for (long &x : preSum) {
        st.insert(x);
        st.insert(x - lower);
        st.insert(x - upper);
    }
    unordered_map<long, int> values;
    int idx = 0;
    for (long x : st) values[x] = idx++;
    int ans = 0;
    BIT bit(values.size());
    for (int i = 0; i < preSum.size(); i++) {
        int left = values[preSum[i] - upper], right = values[preSum[i] - lower];
        ans += bit.query(right + 1) - bit.query(left);
        bit.add(values[preSum[i]] + 1, 1);
    }
    return ans;
}

int main() {
    return 0;
}
