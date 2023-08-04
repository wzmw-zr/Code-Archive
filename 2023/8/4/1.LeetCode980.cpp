/*************************************************************************
	> File Name: 1.LeetCode980.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月04日 星期五 09时14分37秒
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
#include <functional>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

using PII = pair<int, int>;

int uniquePathsIII(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  int zeros = 0, start_x, start_y, end_x, end_y;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0)
        zeros++;
      if (grid[i][j] == 1)
        start_x = i, start_y = j;
      if (grid[i][j] == 2)
        end_x = i, end_y = j;
    }
  }
  int ans = 0;
  set<PII> path;
  function<void(int, int)> dfs = [&](int x, int y){
    if (x == end_x && y == end_y) {
      if (path.size() == zeros + 1)
        ans++;
      return ;
    }
    PII pos(x, y);
    path.insert(pos);
    for (int i = 0; i < 4; i++) {
      int x_t = x + dir[i][0];
      int y_t = y + dir[i][1];
      if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n)
        continue;
      if (path.count(PII(x_t, y_t)))
        continue;
      if (grid[x_t][y_t] == -1)
        continue;
      dfs(x_t, y_t);
    }
    path.erase(pos);
  };
  dfs(start_x, start_y);
  return ans;
}

int main() {
  return 0;
}
