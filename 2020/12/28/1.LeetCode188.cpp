/*************************************************************************
	> File Name: 1.LeetCode188.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月28日 星期一 08时23分56秒
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

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    int m = min(n, k);
    int dp[n + 1][k + 1][2];
    memset(dp, -1, sizeof(dp));
    int max_temp = INT32_MIN;
    int ans = INT32_MIN;
    for (int i = 0; i < n; i++) {
        dp[i][1][0] = prices[i] * -1;
        if (i) dp[i][1][1] = max_temp + prices[i];
        max_temp = max(max_temp, dp[i][1][0]);
    }
    for (int i = 2; i <= m; i++) {
        int mmax_1 = INT32_MIN, mmax_2 = INT32_MIN;
        for (int j = 0; j < 2 * (i - 1); j++) mmax_1 = max(mmax_1, dp[j][i - 1][1]);
        int flag = 0;
        for (int j = 2 * (i - 1); j < n; j++) {
            dp[j][i][0] = mmax_1 - prices[j];
            if (flag) dp[j][i][1] = mmax_2 + prices[j];
            flag = 1;
            mmax_1 = max(mmax_1, dp[j][i - 1][1]);
            mmax_2 = max(mmax_2, dp[j][i][0]);
        }
    }
    return max(dp[n - 1][m][0], dp[n - 1][m][1]);
}

int main() {
    return 0;
}
