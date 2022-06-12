/*************************************************************************
	> File Name: 3.LeetCode5270.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月12日 星期日 10时44分03秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
  int m = grid.size(), n = grid[0].size();
  int dp[m][n];
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i < n; i++) dp[0][i] = grid[0][i];
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + moveCost[grid[i][k]][j]);
      }
      dp[i + 1][j] += grid[i + 1][j];
    }
  }
  int mmin = INT32_MAX;
  for (int i = 0; i < n; i++) mmin = min(mmin, dp[m - 1][i]);
  return mmin;
}

int main() {
  return 0;
}
