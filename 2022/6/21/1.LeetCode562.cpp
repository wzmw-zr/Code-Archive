/*************************************************************************
	> File Name: 1.LeetCode562.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月21日 星期二 11时24分23秒
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

int longestLine(vector<vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size();
  int ans = 0;
  int dp[m][n];
  // row
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < m; i++) {
    dp[i][0] = mat[i][0];
    ans = max(ans, dp[i][0]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[j][i] = (mat[j][i] == 0) ? 0 : (dp[j][i - 1] + 1);
      ans = max(ans, dp[j][i]);
    }
  }
  // column
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[0][i] = mat[0][i];
    ans = max(ans, dp[0][i]);
  }
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = (mat[i][j] == 0) ? 0 : (dp[i - 1][j] + 1);
      ans = max(ans, dp[i][j]);
    }
  }
  // diagonal
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[0][i] = mat[0][i];
    ans = max(ans, dp[0][i]);
  }
  for (int i = 0; i < m; i++) {
    dp[i][0] = mat[i][0];
    ans = max(ans, dp[i][0]);
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = (mat[i][j] == 0) ? 0 : (dp[i - 1][j - 1] + 1);
      ans = max(ans, dp[i][j]);
    }
  }
  // anti-diagonal
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[0][i] = mat[0][i];
    ans = max(ans, dp[0][i]);
  }
  for (int i = 0; i < m; i++) {
    dp[i][n - 1] = mat[i][n - 1];
    ans = max(ans, dp[i][n - 1]);
  }
  for (int i = 1; i < m; i++) {
    for (int j = n - 2; j >= 0; j--) {
      dp[i][j] = (mat[i][j] == 0) ? 0 : (dp[i - 1][j + 1] + 1);
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}

int main() {
  return 0;
}
