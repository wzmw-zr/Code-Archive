/*************************************************************************
	> File Name: 3.LeetCode1262.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月02日 星期三 15时31分43秒
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

int maxSumDivThree(vector<int>& nums) {
    int n = nums.size();
    int dp[n][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        int rest = nums[i - 1] % 3;
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
        if ((dp[i - 1][(3 - rest) % 3] + rest) % 3 == 0) dp[i][0] = max(dp[i][0], dp[i - 1][(3 - rest) % 3] + nums[i - 1]);
        if ((dp[i - 1][(4 - rest) % 3] + rest) % 3 == 1) dp[i][0] = max(dp[i][0], dp[i - 1][(4 - rest) % 3] + nums[i - 1]);
        if ((dp[i - 1][(5 - rest) % 3] + rest) % 3 == 2) dp[i][0] = max(dp[i][0], dp[i - 1][(4 - rest) % 3] + nums[i - 1]);
    }
    return dp[n][0];
}

int main() {
    return 0;
}
