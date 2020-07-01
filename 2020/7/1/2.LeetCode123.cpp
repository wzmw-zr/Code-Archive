/*************************************************************************
	> File Name: 2.LeetCode123.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月01日 星期三 10时32分51秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<cinttypes>
using namespace std;

int maxProfit(vector<int> &prices) {
    int p_len = prices.size();
    int dp[p_len + 5][5][5];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 2; i++) {
        dp[0][i][0] = 0;
        dp[0][i][1] = INT32_MIN; 
    }
#if 0
    for (int i = 0; i <= p_len; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = INT32_MIN;
    }
#endif
    for (int i = 1; i <= p_len; i++) {
        dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1] + prices[i - 1]);
        dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] - prices[i - 1]);
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i - 1]);

        dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][2][0] - prices[i - 1]);

    }
    return dp[p_len][0][0];
}

int main() {
    int n;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prices.push_back(x);
    }
    cout << maxProfit(prices) << endl;
    return 0;
}
