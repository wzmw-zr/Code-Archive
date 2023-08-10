/*************************************************************************
	> File Name: 1.LeetCode1289.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月10日 星期四 10时16分33秒
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
#include <cstdint>
using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
  int n = grid.size();
  vector<vector<int>> check(n, vector<int>(n, 0));
  vector<vector<int>> vals = grid;
  function<int(int, int)> dfs = [&](int row, int col) -> int {
    if (row == n - 1)
      return grid[row][col];
    if (check[row][col])
      return vals[row][col];
    int ans = INT32_MAX;
    for (int i = 0; i < n; i++) {
      if (i == col)
        continue;
      ans = min(ans, dfs(row + 1, i));
    }
    check[row][col] = 1;
    return vals[row][col] = ans + grid[row][col];
  };
  int ans = INT32_MAX;
  for (int i = 0; i < n; i++)
    ans = min(ans, dfs(0, i));
  return ans;
}

int main() {
  return 0;
}
