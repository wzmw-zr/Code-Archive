/*************************************************************************
	> File Name: 1.LeetCode6440.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月28日 星期日 10时33分32秒
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

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> top_left(m, vector<int>(n, 0));
  vector<vector<int>> bottom_right(m, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    unordered_set<int> st;
    for (int j = 0; j < m && (i + j) < n;j++) {
      top_left[j][i + j] = st.size();
      st.insert(grid[j][i + j]);
    }
  }
  for (int i = 0; i < m; i++) {
    unordered_set<int> st;
    for (int j = 0; j < n && (i + j) < m; j++) {
      top_left[i + j][j] = st.size();
      st.insert(grid[i + j][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    unordered_set<int> st;
    for (int j = 0; j < m && (i - j) >= 0; j++) {
      bottom_right[m - 1 - j][i - j] = st.size();
      st.insert(grid[m - 1 - j][i - j]);
    }
  }
  for (int i = 0; i < m; i++) {
    unordered_set<int> st;
    for (int j = 0; j < n && (i - j) >= 0; j++) {
      bottom_right[i - j][n - 1 - j] = st.size();
      st.insert(grid[i - j][n - 1 - j]);
    }
  }
  vector<vector<int>> ans(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      ans[i][j] = abs(top_left[i][j] - bottom_right[i][j]);
  }
  return ans;
}

int main() {
  return 0;
}
