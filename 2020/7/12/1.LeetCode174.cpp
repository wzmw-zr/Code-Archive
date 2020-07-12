/*************************************************************************
	> File Name: 1.LeetCode174.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月12日 星期日 07时08分49秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int res = 0, ans = 0;
    int x_len = dungeon.size();
    if (!x_len) return 1;
    int y_len = dungeon[0].size();
    if (!y_len) return 1;

    vector<vector<int>> dp(x_len + 5, vector<int>(y_len + 5, 0));
    vector<vector<int>> sum(x_len + 5, vector<int>(y_len + 5, 0));

    sum[0][0] = dungeon[0][0];
    if (sum[0][0] >= 0) dp[0][0] = 0;
    else dp[0][0] = -sum[0][0];

    for (int i = 1; i < x_len; i++) {
        sum[i][0] = sum[i - 1][0] + dungeon[i][0];
        if (sum[i][0] < 0) dp[i][0] = max(dp[i - 1][0], -sum[i][0]);
        else dp[i][0] = dp[i - 1][0];
    }

    for (int i = 1; i < y_len; i++) {
        sum[0][i] = sum[0][i - 1] + dungeon[0][i];
        if (sum[0][i] < 0) dp[0][i] = max(dp[0][i - 1], -sum[0][i]);
        else dp[0][i] = dp[0][i - 1];
    }

    for (int i = 1; i < x_len; i++) {
        for (int j = 1; j < y_len; j++) {
            sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + dungeon[i][j];
            if (sum[i][j] < 0) dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), -sum[i][j]);
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x_len - 1][y_len - 1];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dungeon(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            dungeon[i][j] = x;
        }
    }
    cout << calculateMinimumHP(dungeon) << endl;
    return  0;
}
