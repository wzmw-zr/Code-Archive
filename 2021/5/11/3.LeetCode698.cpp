/*************************************************************************
	> File Name: 3.LeetCode698.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月11日 星期二 14时24分59秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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


bool dfs(vector<int> &dp, int status, int p, int k, unordered_map<int, bool> &mp) {
    if (k == 0) return true;
    if (mp.count(status)) return mp[status];
    bool ans = false;
    for (int i = status; i && !ans; i = (i - 1) & status) {
        if (dp[i] != p) continue;
        ans |= dfs(dp, status - i, p, k - 1, mp);
    }
    mp[status] = ans;
    return ans;
}


bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    for (int x : nums) 
        sum += x;
    if (sum % k) 
        return false;
    vector<int> dp(1 << n, 0);
    for (int i = 1; i < (1 << n); i++) {
        int l = __builtin_ctz(i);
        dp[i] = dp[i - (1 << l)] + nums[l];
    }
    int p = sum / k;
    int status = (1 << n) - 1;
    unordered_map<int, bool> mp;
    bool ans = dfs(dp, status, p, k, mp);
    return ans;
}

int main() {
    int k;
    cin >> k;
    int num;
    vector<int> nums;
    while (cin >> num) nums.push_back(num);
    cout << (canPartitionKSubsets(nums, k) ? "True" : "False") << endl;
    return 0;
}
