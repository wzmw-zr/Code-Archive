/*************************************************************************
	> File Name: 4.LeetCode6433.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月14日 星期日 10时41分45秒
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
using namespace std;

using PII = pair<int, int>;
int dir[3][2] = {-1, 1, 0, 1, 1, 1};

int maxMoves(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<PII> pos;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      pos.push_back(PII(i, j));
  sort(pos.begin(), pos.end(), [&](PII &a, PII &b){
    return grid[a.first][a.second] > grid[b.first][b.second];
  });
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (auto && [x, y] : pos) {
    for (int i = 0; i < 3; i++) {
      int x_t = x + dir[i][0];
      int y_t = y + dir[i][1];
      if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || grid[x_t][y_t] <= grid[x][y])
        continue;
      dp[x][y] = max(dp[x][y], dp[x_t][y_t] + 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
    ans = max(ans, dp[i][0]);
  return ans;
}

int main() {
  return 0;
}
