/*************************************************************************
	> File Name: 3.LeetCode1746.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月18日 星期四 15时51分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int maxSumAfterOperation(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    int dp[2] = {nums[0], nums[0] * nums[0]};
    ans = max(dp[0], dp[1]);
    for (int i = 1; i < n; i++) {
        dp[1] = max(max(dp[0] + nums[i] * nums[i], nums[i] * nums[i]), dp[1] + nums[i]);
        dp[0] = max(dp[0] + nums[i], nums[i]);
        ans = max(ans, max(dp[0], dp[1]));
    }
    return ans;
}

int main() {
    return 0;
}
