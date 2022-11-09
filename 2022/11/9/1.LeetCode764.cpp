/*************************************************************************
	> File Name: 1.LeetCode764.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月09日 星期三 09时29分35秒
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

int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
  vector<vector<int>> grids(n, vector<int>(n, 1));
  vector<vector<int>> left(n, vector<int>(n, 0));
  vector<vector<int>> right(n, vector<int>(n, 0));
  vector<vector<int>> top(n, vector<int>(n, 0));
  vector<vector<int>> down(n, vector<int>(n, 0));
  for (auto && mine : mines)
    grids[mine[0]][mine[1]] = 0;
  for (int i = 0; i < n; i++) {
    top[0][i] = grids[0][i];
    left[i][0] = grids[i][0];
    down[n - 1][i] = grids[n - 1][i];
    right[i][n - 1] = grids[i][n - 1];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      top[i][j] = grids[i][j] == 0 ? 0 : (top[i - 1][j] + 1);
      left[j][i] = grids[j][i] == 0 ? 0 : (left[j][i - 1] + 1);
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      down[i][j] = grids[i][j] == 0 ? 0 : (down[i + 1][j] + 1);
      right[j][i] = grids[j][i] == 0 ? 0 : (right[j][i + 1] + 1);
    }
  }
  int mmax = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mmax = max({mmax, min({left[i][j], right[i][j], top[i][j], down[i][j]})});
    }
  }
  return mmax;
}

int main() {
  return 0;
}
