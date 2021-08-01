/*************************************************************************
	> File Name: 4.LeetCode5833.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月01日 星期日 11时47分29秒
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

int countSpecialSubsequences(vector<int>& nums) {
    const long MOD = 1e9 + 7;
    int n = nums.size();
    long dp[n + 1][3];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            dp[i + 1][0] = (2 * dp[i][0] + 1) % MOD;
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][2];
        } else if (nums[i] == 1) {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = (2 * dp[i][1] + dp[i][0]) % MOD;
            dp[i + 1][2] = dp[i][2];
        } else {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = (2 * dp[i][2] + dp[i][1]) % MOD;
        }
    }
    return dp[n][2];
}

int main() {
    return 0;
}
