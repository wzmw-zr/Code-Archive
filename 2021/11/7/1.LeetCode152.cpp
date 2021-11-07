/*************************************************************************
	> File Name: 1.LeetCode152.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月07日 星期日 10时02分48秒
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

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0) {
            dp[i + 1][0] = max(nums[i], dp[i][0] * nums[i]);
            dp[i + 1][1] = min(0, dp[i][1] * nums[i]);
        } else {
            dp[i + 1][0] = max(0, dp[i][1] * nums[i]);
            dp[i + 1][1] = min(nums[i], dp[i][0] * nums[i]);
        }
    }
    int ans = INT32_MIN;
    for (int i = 0; i <= n; i++) ans = max(ans, dp[i][0]);
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << maxProduct(nums) << endl;
    return 0;
}
