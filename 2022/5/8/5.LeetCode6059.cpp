/*************************************************************************
	> File Name: 5.LeetCode6059.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月08日 星期日 10时55分37秒
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

int check[110][110][220];

bool dfs(vector<vector<char>> &grid, int x, int y, int diff) {
  int m = grid.size(), n = grid[0].size();
  if (x < 0 || x >= m || y < 0 || y >= n) return false;
  diff += (grid[x][y] == '(' ? 1 : -1);
  if (x == m - 1 && y == n - 1) {
    if (diff == 0) return true;
    return false;
  }
  if (diff < 0) return false;
  if (check[x][y][diff] == -1) return false;
  if (check[x][y][diff] == 1) return true;
  if (dfs(grid, x + 1, y, diff)) {
    check[x][y][diff] = 1;
    return true;
  }
  if (dfs(grid, x, y + 1, diff)) {
    check[x][y][diff] = 1;
    return true;
  }
  check[x][y][diff] = -1;
  return false;
}

bool hasValidPath(vector<vector<char>>& grid) {
  int m = grid.size(), n = grid[0].size();
  memset(check, 0, sizeof(check));
  int diff = 0;
  return dfs(grid, 0, 0, diff);
}

int main() {
  return 0;
}
