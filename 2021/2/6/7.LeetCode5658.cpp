/*************************************************************************
	> File Name: 7.LeetCode5658.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月06日 星期六 22时55分22秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int dp[n][2];
    memset(dp, 0, sizeof(dp));
    int ans = abs(nums[0]);
    if (nums[0] > 0) dp[0][0] = nums[0];
    else dp[0][1] = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > 0) {
            dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i]);
            dp[i][1] = (dp[i - 1][1] + nums[i]) < 0 ? dp[i - 1][1] + nums[i] : 0;
        } else {
            dp[i][1] = min(dp[i - 1][1] + nums[i], nums[i]);
            dp[i][0] = (dp[i - 1][0] + nums[i]) > 0 ? dp[i - 1][0] + nums[i] : 0;
        }
        ans = max(ans, max(abs(dp[i][0]), abs(dp[i][1])));
    }
    return ans;
}

int main() {
    return 0;
}
