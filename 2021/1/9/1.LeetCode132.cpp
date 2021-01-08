/*************************************************************************
	> File Name: 1.LeetCode132.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月09日 星期六 00时08分05秒
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

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp[n + 5][3][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 0x3f3f3f3f * -1;
    dp[2][1][1] = 0x3f3f3f3f * -1;
    for (int i = 1; i <= n; i++) {
        dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i - 1]);
        if (i >= 2) dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][1] + prices[i - 1]);
        if (i >= 3) dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][1][0] - prices[i - 1]);
        if (i >= 4) dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][1][1] + prices[i - 1]);
    }
    return max(0, max(dp[n][1][0], dp[n][2][0]));
}

int main() {
    return 0;
}
