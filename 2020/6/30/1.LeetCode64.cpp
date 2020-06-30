/*************************************************************************
	> File Name: 1.LeetCode64.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月30日 星期二 07时48分07秒
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

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size() + 5, vector<int>(grid[0].size() + 5, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < grid[0].size(); i++) dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int i = 1; i < grid.size(); i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[0].size(); j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        grid.push_back(tmp);
    }
    cout << minPathSum(grid) << endl;
    #if 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    #endif
    return 0;
}
