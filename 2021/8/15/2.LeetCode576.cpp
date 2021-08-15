/*************************************************************************
	> File Name: 2.LeetCode576.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月15日 星期日 11时08分33秒
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

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int dp[m + 5][n + 5][maxMove + 5];
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    const int MOD = 1e9 + 7;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= maxMove; i++) {
        for (int j = 1; j <= m; j++) dp[j][0][i] = dp[j][n + 1][i] = 1;
        for (int j = 1; j <= n; j++) dp[0][j][i] = dp[m + 1][j][i] = 1;
    }
    for (int i = 1; i <= maxMove; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                for (int ind = 0; ind < 4; ind++) 
                    dp[j][k][i] = (dp[j][k][i] + dp[j + dir[ind][0]][k + dir[ind][1]][i - 1]) % MOD;
            }
        }
    }
    return dp[startRow + 1][startColumn + 1][maxMove];
}

int main() {
    return 0;
}
