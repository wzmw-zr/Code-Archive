/*************************************************************************
	> File Name: 1.LeetCode64.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月23日 星期四 01时01分09秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
    for (int i = 1; i <= grid.size(); i++) dp[1][i] = dp[1][i - 1] + grid[0][i - 1];
    for (int i = 1; i <= grid[0].size(); i++) dp[i][1] = dp[i - 1][1] + grid[i - 1][0];
    for (int i = 2; i <= grid.size(); i++) {
        for (int j = 2; j <= grid[0].size(); j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp[grid.size()][grid[0].size()];
}

int main() {
    return 0;
}
