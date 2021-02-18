/*************************************************************************
	> File Name: 2.LeetCode1746.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月18日 星期四 15时38分28秒
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

int maxSumAfterOperation(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    int dp[n][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = nums[0];
    dp[0][1] = nums[0] * nums[0];
    ans = max(dp[0][0], dp[0][1]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i]);
        dp[i][1] = max(max(dp[i - 1][0] + nums[i] * nums[i], nums[i] * nums[i]), dp[i - 1][1] + nums[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    return ans;
}

int main() {
    return 0;
}
