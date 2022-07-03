/*************************************************************************
	> File Name: 5.LeetCode6110.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月03日 星期日 11时02分48秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PII = pair<int, int>;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

long MOD = 1e9 + 7;

int countPaths(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<long>> cnts(m, vector<long>(n, 1));
  auto cmp = [&](PII &x, PII &y) -> bool {
    return grid[x.first][x.second] > grid[y.first][y.second];
  };
  priority_queue<PII, vector<PII>, decltype(cmp)> que(cmp);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) que.push(PII(i, j));
  }
  while (!que.empty()) {
    auto [x, y] = que.top();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int x_t = x + dir[i][0];
      int y_t = y + dir[i][1];
      if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || grid[x_t][y_t] <= grid[x][y]) continue;
      cnts[x_t][y_t] = (cnts[x_t][y_t] + cnts[x][y]) % MOD;
    }
  }
  long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ans = (ans + cnts[i][j]) % MOD;
    }
  }
  return ans;
}

int main() {
  return 0;
}
