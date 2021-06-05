/*************************************************************************
	> File Name: 1.LeetCode474.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月06日 星期日 00时05分37秒
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
    int dp[len + 1][m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len; i++) {
        int x = 0, y = 0;
        for (int j = 0; strs[i - 1][j]; j++) {
            x += strs[i - 1][j] == '0' ? 1 : 0;
            y += strs[i - 1][j] == '0' ? 0 : 1;
        }
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) 
                dp[i][j][k] = dp[i - 1][j][k];
        }
        for (int j = x; j <= m; j++) {
            for (int k = y; k <= n; k++) {
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - x][k - y] + 1);
            }
        }
    }
    return dp[len][m][n];
}

int main() {
    return 0;
}
