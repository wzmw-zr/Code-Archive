/*************************************************************************
	> File Name: 3.LeetCode5811.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月11日 星期日 10时55分46秒
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

// WA
const long MOD = 1e9 + 7;

int colorTheGrid(int m, int n) {
    long dp[m][n][3];
    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 1;
    for (int i = 1; i < n; i++) {
        dp[0][i][0] = (dp[0][i - 1][1] + dp[0][i - 1][2]) % MOD;
        dp[0][i][1] = (dp[0][i - 1][0] + dp[0][i - 1][2]) % MOD;
        dp[0][i][2] = (dp[0][i - 1][0] + dp[0][i - 1][1]) % MOD;
    }
    for (int i = 1; i < m; i++) {
        dp[i][0][0] = (dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
        dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][0][2]) % MOD;
        dp[i][0][2] = (dp[i - 1][0][0] + dp[i - 1][0][1]) % MOD;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j][0] = ((dp[i][j - 1][1] + dp[i][j - 1][2]) * (dp[i - 1][j][1] + dp[i - 1][j][2])) % MOD;
            dp[i][j][1] = ((dp[i][j - 1][0] + dp[i][j - 1][2]) * (dp[i - 1][j][0] + dp[i - 1][j][2])) % MOD;
            dp[i][j][2] = ((dp[i][j - 1][0] + dp[i][j - 1][1]) * (dp[i - 1][j][0] + dp[i - 1][j][1])) % MOD;
        }
    }
    long ans = (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1] + dp[m - 1][n - 1][2]) % MOD;
    return ans;
}

int main() {
    return 0;
}
