/*************************************************************************
	> File Name: 5.LeetCode6203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月09日 星期日 10时48分20秒
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

long MOD = 1e9 + 7;

int numberOfPaths(vector<vector<int>>& grid, int k) {
  int m = grid.size(), n = grid[0].size();
  long dp[m + 1][n + 1][k + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0][grid[0][0] % k] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int rest = (j + grid[0][i]) % k;
      dp[0][i][rest] = (dp[0][i][rest] + dp[0][i - 1][j]) % MOD;
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < k; j++) {
      int rest = (j + grid[i][0]) % k;
      dp[i][0][rest] = (dp[i][0][rest] + dp[i - 1][0][j]) % MOD;
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      for (int p = 0; p < k; p++) {
        int rest = (p + grid[i][j]) % k;
        dp[i][j][rest] = (dp[i][j][rest] + dp[i - 1][j][p] + dp[i][j - 1][p]) % MOD;
      }
    }
  }
  return dp[m - 1][n - 1][0];
}

int main() {
  return 0;
}
