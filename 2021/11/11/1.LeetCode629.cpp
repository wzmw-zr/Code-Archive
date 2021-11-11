/*************************************************************************
	> File Name: 1.LeetCode629.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月11日 星期四 09时22分01秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

const long MOD = 1e9 + 7;

int kInversePairs(int n, int k) {
    long dp[n + 1][k + 1];
    long pre[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    dp[1][0] = 1;
    pre[1][0] = 1;
    for (int i = 1; i <= k; i++) pre[1][i] = (pre[1][i - 1] + dp[1][i]) % MOD;
    for (int i = 2; i <= n; i++) {
        int t = min(i * (i - 1) / 2, k);
        for (int j = 0; j <= t; j++) {
            if ((j - i + 1) <= 0) dp[i][j] = pre[i - 1][j];
            else dp[i][j] = (pre[i - 1][j] - pre[i - 1][j - i] + MOD) % MOD;
            // for (int p = max(0, j - i + 1); p <= j; p++) dp[i][j] = (dp[i][j] + dp[i - 1][p]) % MOD;
        }
        pre[i][0] = 1;
        for (int j = 1; j <= k; j++) pre[i][j] = (pre[i][j - 1] + dp[i][j]) % MOD;
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << kInversePairs(n, k) << endl;
    return 0;
}
