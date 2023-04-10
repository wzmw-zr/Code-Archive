/*************************************************************************
	> File Name: 3.LeetCode2617.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月10日 星期一 19时50分40秒
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

int minimumVisitedCells(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> ans(m, vector<int>(n, -1));
  set<int> rows[m], cols[n];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      rows[i].insert(j);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cols[i].insert(j);
  queue<PII> que;
  que.push(PII(0, 0));
  ans[0][0] = 1;
  rows[0].erase(0);
  cols[0].erase(0);

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    int l = y + 1, r = min(n - 1, y + grid[x][y]);
    auto iter = rows[x].lower_bound(l);
    while (iter != rows[x].end() && *iter <= r) {
      que.push(PII(x, *iter));
      ans[x][*iter] = ans[x][y] + 1;
      cols[*iter].erase(x);
      iter = rows[x].erase(iter);
    }

    int up = x + 1, down = min(m - 1, x + grid[x][y]);
    iter = cols[y].lower_bound(up);
    while (iter != cols[y].end() && *iter <= down) {
      que.push(PII(*iter, y));
      ans[*iter][y] = ans[x][y] + 1;
      rows[*iter].erase(y);
      iter = cols[y].erase(iter);
    }
  }

  return ans[m - 1][n - 1];
}

int main() {
  return 0;
}
