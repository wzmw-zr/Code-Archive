/*************************************************************************
	> File Name: 1.LeetCode1269.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月13日 星期四 00时06分50秒
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

const int MOD = 1e9 + 7;

int numWays(int steps, int arrLen) {
    int mmin = min(steps, arrLen - 1);
    int dp[mmin + 1][steps + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= steps; i++) {
        int t = min(i, arrLen - 1);
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        for (int j = 1; j < t; j++) 
            dp[j][i] = (((dp[j - 1][i - 1] + dp[j][i - 1]) % MOD) + dp[j + 1][i - 1]) % MOD;
        if (t > 0) 
            dp[t][i] = (dp[t][i - 1] + dp[t - 1][i - 1]) % MOD;
    }
    return dp[0][steps];
}

int main() {
    int steps, arrLen;
    cin >> steps >> arrLen;
    cout << numWays(steps, arrLen) << endl;
    return 0;
}
