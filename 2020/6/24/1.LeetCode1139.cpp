/*************************************************************************
	> File Name: 1.LeetCode1139.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月24日 星期三 07时25分54秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int check(vector<vector<int>> &grid, int len) {
    return 0;
}

int largeset1BorderedSquare(vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp;
    for (int i)
    dp[grid.size() + 5][grid[0].size() + 5][2];
    int res = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) dp[i][j][0] = 0;
            else {
                if (j == 0) dp[i][j][0] = 1;
                else dp[i][j][0] = dp[i][j - 1][0] + 1;
            }
        }
    }

    for (int j = 0; j < grid[0].size(); j++) {
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][j] == 0) dp[i][j][1] = 0;
            else {
                if (i == 0) dp[i][j][1] = 1;
                else dp[i][j][1] = dp[i - 1][j][1] + 1;
            }
        }
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); i++) {
            int len = min(dp[i][j][0], dp[i][j][1]);
            while (len && !check(grid, len)) len--;
            res = max(res, len);
        }
    }
}

int main() {
    return 0;
}

