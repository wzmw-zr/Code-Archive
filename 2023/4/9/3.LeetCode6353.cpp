/*************************************************************************
	> File Name: 3.LeetCode6353.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月09日 星期日 11时05分48秒
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
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

// TLE
using TIII = tuple<int, int, int>;

int minimumVisitedCells(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> check(m, vector<int>(n, 0));
  queue<TIII> que;
  que.push(TIII(0, 0, 1));
  check[0][0] = 1;
  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      auto [x, y, step] = que.front();
      que.pop();
      if ((x == m - 1) && (y == n - 1))
        return step;
      for (int k = y + 1; k <= y + grid[x][y] && k < n; k++) {
        if (check[x][k])
          continue;
        que.push(TIII(x, k, step + 1));
        check[x][k] = 1;
      }
      for (int k = x + 1; k <= x + grid[x][y] && k < m; k++) {
        if (check[k][y])
          continue;
        que.push(TIII(k, y, step + 1));
        check[k][y] = 1;
      }
    }
  }
  return -1;
}

int main() {
  return 0;
}
