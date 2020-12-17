/*************************************************************************
	> File Name: 1.LeetCode714.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月17日 星期四 08时24分33秒
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

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int dp[n][4];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = prices[0] * -1;
    if (n >= 2) {
        dp[1][0] = prices[1] * -1;
        dp[1][1] = dp[0][0] + prices[1] - fee;
        dp[1][2] = dp[0][0];
        dp[1][3] = 0;
    }
    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][3]) - prices[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + prices[i] - fee;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][3] = max(dp[i - 1][1], dp[i - 1][3]);
    }
    return max(max(dp[n - 1][0], dp[n - 1][1]), max(dp[n - 1][2], dp[n - 1][3]));
}

int main() {
    int fee, n;
    vector<int> prices;
    cin >> fee;
    while (cin >> n) prices.push_back(n);
    cout << maxProfit(prices, fee) << endl;
    return 0;
}
