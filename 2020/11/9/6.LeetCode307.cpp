/*************************************************************************
	> File Name: 6.LeetCode307.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月09日 星期一 16时11分42秒
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

    void add(int ind, int val) {
        while (ind <= n) {
            tree[ind] += val;
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

class NumArray {
public:
    BIT bit;
    vector<int> arr;
    NumArray(vector<int>& nums) : bit(nums.size()), arr(nums) {
        for (int i = 0; i < nums.size(); i++) bit.add(i + 1, nums[i]);
    }

    void update(int i, int val) {
        bit.add(i + 1, val - arr[i]);
        arr[i] = val;
    }

    int sumRange(int i, int j) {
        return bit.query(j + 1) - bit.query(i);
    }
};

int main() {
    return 0;
}
