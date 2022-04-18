/*************************************************************************
	> File Name: 3.LeetCode6072.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月18日 星期一 10时08分10秒
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

int maxTrailingZeros(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<PII>> h_pre(m + 1, vector<PII>(n + 1, PII(0, 0)));
  vector<vector<PII>> h_suf(m + 1, vector<PII>(n + 1, PII(0, 0)));
  vector<vector<PII>> v_pre(m + 1, vector<PII>(n + 1, PII(0, 0)));
  vector<vector<PII>> v_suf(m + 1, vector<PII>(n + 1, PII(0, 0)));
  auto calculate = [](int x) -> PII {
    int two = 0, five = 0;
    while (x % 2 == 0) {
      two++;
      x /= 2;
    }
    while (x % 5 == 0) {
      five++;
      x /= 5;
    }
    return PII(two, five);
  };
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      PII t = calculate(grid[i][j]);
      h_pre[i][j + 1] = PII(h_pre[i][j].first + t.first, h_pre[i][j].second + t.second);
    }
    for (int j = n - 1; j >= 0; j--) {
      PII t = calculate(grid[i][j]);
      h_suf[i][j] = PII(h_suf[i][j + 1].first + t.first, h_suf[i][j + 1].second + t.second);
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      PII t = calculate(grid[i][j]);
      v_pre[i + 1][j] = PII(v_pre[i][j].first + t.first, v_pre[i][j].second + t.second);
    }
    for (int i = m - 1; i >= 0; i--) {
      PII t = calculate(grid[i][j]);
      v_suf[i][j] = PII(v_suf[i + 1][j].first + t.first, v_suf[i + 1][j].second + t.second);
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      PII t = calculate(grid[i][j]);
      PII x1 = h_pre[i][j + 1];
      PII x2 = v_pre[i + 1][j];
      PII x3 = h_suf[i][j];
      PII x4 = v_suf[i][j];
      ans = max({
        ans, 
        min(x1.first + x2.first - t.first, x1.second + x2.second - t.second), 
        min(x1.first + x4.first - t.first, x1.second + x4.second - t.second),
        min(x3.first + x2.first - t.first, x3.second + x2.second - t.second), 
        min(x3.first + x4.first - t.first, x3.second + x4.second - t.second)
      });
    }
  }
  return ans;
}

int main() {
  return 0;
}
