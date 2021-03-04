/*************************************************************************
	> File Name: 4.LeetCode673.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月04日 星期四 16时46分31秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int max_len = 1;
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (dp[i] > dp[j] + 1) continue;
                if (dp[i] == dp[j] + 1) cnt[i] += cnt[j];
                else {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
        }
        max_len = max(max_len, dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == max_len) ans += cnt[i];
    }
    return ans;
}

int main() {
    return 0;
}
