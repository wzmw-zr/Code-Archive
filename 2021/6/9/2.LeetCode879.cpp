/*************************************************************************
	> File Name: 2.LeetCode879.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月09日 星期三 01时00分51秒
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

// TLE
const int MOD = 1e9 + 7;

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int g = group.size();
    int sum = 0;
    for (int x : profit) sum += x;
    int dp[2][n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][n][0] = 1;
    for (int i = 1; i <= g; i++) {
        int t = i & 1;
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= sum; k++) {
                dp[t][j][k] = dp[!t][j][k];
                if (j + group[i - 1] > n) continue;
                if (k < profit[i - 1]) continue;
                dp[t][j][k] += dp[!t][j + group[i - 1]][k - profit[i - 1]];
                dp[t][j][k] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = minProfit; j <= sum; j++) {
            ans = (ans + dp[g & 1][i][j]) % MOD;
        }
    }
    return ans;
}

int main() {
    return 0;
}
