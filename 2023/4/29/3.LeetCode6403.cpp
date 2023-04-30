/*************************************************************************
	> File Name: 3.LeetCode6403.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月29日 星期六 22时39分20秒
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

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int findMaxFish(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> check(m, vector<int>(n, 0));
  int ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (check[i][j] || !grid[i][j])
        continue;
      queue<PII> que;
      que.push(PII(i, j));
      check[i][j] = 1;
      int sum = 0;
      while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        sum += grid[x][y];
        for (int k = 0; k < 4; k++) {
          int x_t = x + dir[k][0];
          int y_t = y + dir[k][1];
          if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || check[x_t][y_t] || !grid[x_t][y_t])
            continue;
          que.push(PII(x_t, y_t));
          check[x_t][y_t] = 1;
        }
      }
      ans = max(ans, sum);
    }
  }
  return ans;
}

int main() {
  return 0;
}
