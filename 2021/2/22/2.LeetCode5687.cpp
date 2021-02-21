/*************************************************************************
	> File Name: 2.LeetCode5687.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月22日 星期一 00时48分03秒
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

int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size(), m = multipliers.size();
    int len = n - m;
    vector<int> dp(m + 1, 0);
    for (int i = m - 1; i >= 0; i--, len++) {
        if (len == 0) {
            for (int j = 0; j < n; j++) dp[j] = nums[j] * multipliers[i];
            continue;
        }
        for (int j = 0; j <= i; j++) dp[j] = max(dp[j] + nums[j + len] * multipliers[i], dp[j + 1] + nums[j] * multipliers[i]);
    }
    return dp[0];
}

int main() {
    return 0;
}
