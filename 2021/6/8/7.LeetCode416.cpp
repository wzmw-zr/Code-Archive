/*************************************************************************
	> File Name: 7.LeetCode416.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月08日 星期二 17时09分36秒
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

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int x : nums) sum += x;
    if (sum & 1) return false;
    int n = nums.size();
    int target = sum / 2;
    int dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] |= dp[i - 1][j];
            if (j >= nums[i - 1]) dp[i][j] |= dp[i - 1][j - nums[i - 1]];
        }
        if (dp[i][target]) return true;
    }
    return false;
}

int main() {
    return 0;
}
