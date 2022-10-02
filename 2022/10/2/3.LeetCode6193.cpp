/*************************************************************************
	> File Name: 3.LeetCode6193.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月02日 星期日 10时34分02秒
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

int maxSum(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<long>> pre(m + 1, vector<long>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + grid[i][j];
    }
  }
  int ans = INT32_MIN;
  for (int i = 0; i <= m - 3; i++) {
    for (int j = 0; j <= n - 3; j++) {
      int val = pre[i + 3][j + 3] - pre[i + 3][j] - pre[i][j + 3] + pre[i][j] - grid[i + 1][j] - grid[i + 1][j + 2];
      ans = max(ans, val);
    }
  }
  return ans;
}

int main() {
  return 0;
}
