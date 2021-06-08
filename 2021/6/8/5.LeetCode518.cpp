/*************************************************************************
	> File Name: 5.LeetCode518.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月08日 星期二 16时52分26秒
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

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[n + 1][amount + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
        }
    }
    return dp[n][amount];
}

int main() {
    return 0;
}
