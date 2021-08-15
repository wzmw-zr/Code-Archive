/*************************************************************************
	> File Name: 3.LeetCode552.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月15日 星期日 13时28分45秒
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

int checkRecord(int n) {
    const long MOD = 1e9 + 7;
    long dp[n][2][3];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
        dp[i][0][1] = dp[i - 1][0][0];
        dp[i][0][2] = dp[i - 1][0][1];
        dp[i][1][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2] + dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
        dp[i][1][1] = dp[i - 1][1][0];
        dp[i][1][2] = dp[i - 1][1][1];
    }
    long ans = (dp[n - 1][0][0] + dp[n - 1][0][1] + dp[n - 1][0][2] + dp[n - 1][1][0] + dp[n - 1][1][1] + dp[n - 1][1][2]) % MOD;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << checkRecord(n) << endl;
    return 0;
}
