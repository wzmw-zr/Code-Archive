/*************************************************************************
	> File Name: 1.LeetCode474.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月13日 星期六 07时45分14秒
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

int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    int cnts[len][2];
    memset(cnts, 0, sizeof(cnts));
    for (int i = 0; i < len; i++) {
        for (int j = 0; strs[i][j]; j++) cnts[i][strs[i][j] - '0']++;
    }
    int dp[len + 1][m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                if (cnts[i][0] > j || cnts[i][1] > k) {
                    dp[i + 1][j][k] = dp[i][j][k];
                    continue;
                }
                dp[i + 1][j][k] = max(dp[i][j][k], dp[i][j - cnts[i][0]][k - cnts[i][1]] + 1);
                ans = max(ans, dp[i + 1][j][k]);
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
