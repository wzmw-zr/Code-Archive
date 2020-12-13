/*************************************************************************
	> File Name: 4.LeetCode5627.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月13日 星期日 11时05分20秒
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

int stoneGameVII(vector<int>& stones) {
    int n = stones.size();
    int pre[n + 5];
    int dp[n + 5][n + 5][2][2];
    memset(pre, 0, sizeof(pre));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + stones[i - 1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            if (dp[j][j + i - 2][1][1] < dp[j + 1][j + i - 1][1][1]) {
                dp[j][j + i - 1][0][0] = dp[j][j + i - 2][1][0] + pre[j + i - 2] - pre[j - 1];
                dp[j][j + i - 1][0][1] = dp[j][j + i - 2][1][1];
            } else if (dp[j][j + i - 2][1][1] > dp[j + 1][j + i - 1][1][1]) {
                dp[j][j + i - 1][0][0] = dp[j + 1][j + i - 1][1][0] + pre[j + i - 1] - pre[j];
                dp[j][j + i - 1][0][1] = dp[j + 1][j + i - 1][1][1];
            } else {
                dp[j][j + i - 1][0][0] = max(dp[j][j + i - 2][1][0] + pre[j + i - 2] - pre[j - 1], dp[j + 1][j + i - 1][1][0] + pre[j + i - 1] - pre[j]);
                dp[j][j + i - 1][0][1] = dp[j + 1][j + i - 2][1][1];
            }

            if (dp[j][j + i - 2][0][0] < dp[j + 1][j + i - 1][0][0]) {
                dp[j][j + i - 1][1][1] = dp[j][j + i - 2][0][1] + pre[j + i - 2] - pre[j - 1];
                dp[j][j + i - 1][1][0] = dp[j][j + i - 2][0][0];
            } else if (dp[j][j + i - 2][0][0] > dp[j + 1][j + i - 1][0][0]) {
                dp[j][j + i - 1][1][1] = dp[j + 1][j + i - 1][0][1] + pre[j + i - 1] - pre[j];
                dp[j][j + i - 1][1][0] = dp[j + 1][j + i - 1][0][0];
            } else {
                dp[j][j + i - 1][1][1] = max(dp[j][j + i - 2][0][1] + pre[j + i - 2] - pre[j - 1], dp[j + 1][j + i - 1][0][1] + pre[j + i - 1] - pre[j]);
                dp[j][j + i - 1][1][0] = dp[j + 1][j + i - 2][0][0];
            }
        }
    }
    return dp[1][n][0][0] - dp[1][n][0][1];
}

int main() {
    return 0;
}
