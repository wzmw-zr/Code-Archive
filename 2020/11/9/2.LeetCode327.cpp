/*************************************************************************
	> File Name: 2.LeetCode327.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月09日 星期一 09时03分57秒
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
    vector<long> tree;

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
    for (int i = 0; i < nums.size(); i++) preSum[i + 1] = preSum[i] + nums[i];
    set<long> numbers;
    for (long x : preSum) {
        numbers.insert(x);
        numbers.insert(x - upper);
        numbers.insert(x - lower);
    }
    int id = 0, ans = 0;
    unordered_map<long, int> mp;
    for (long x : numbers) mp[x] = ++id;
    BIT bit(numbers.size());
    for (long x : preSum) {
        int left = mp[x - upper], right = mp[x - lower];
        ans += bit.query(right) - bit.query(left - 1);
        bit.add(mp[x], 1);
    }
    return ans;
}

int main() {
    int lower, upper, x;
    vector<int> nums;
    cin >> lower >> upper;
    while (cin >> x) nums.push_back(x);
    cout << countRangeSum(nums, lower, upper) << endl;
    return 0;
}
