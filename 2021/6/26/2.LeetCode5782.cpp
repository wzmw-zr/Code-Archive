/*************************************************************************
	> File Name: 2.LeetCode5782.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月26日 星期六 23时01分35秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
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

long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    long long dp[n][2];
    memset(dp, 0, sizeof(dp));
    dp[0][1] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - (long long) nums[i]);
        dp[i][1] = max(dp[i - 1][1], max((long long) 0, dp[i - 1][0]) + (long long) nums[i]);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    return 0;
}
