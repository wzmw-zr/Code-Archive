/*************************************************************************
	> File Name: 1.LeetCode741.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月10日 星期日 09时25分37秒
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

// WA
const int LEFT = 1;
const int TOP = 2;

int cherryPickup(vector<vector<int>>& grid) {
  int n = grid.size();
  int dp1[n][n], dp2[n][n], path[n][n];
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  memset(path, 0, sizeof(path));
  dp1[0][0] = grid[0][0];
  for (int i = 1; i < n; i++) {
    if (grid[0][i] == -1 || dp1[0][i - 1] == -1) 
      dp1[0][i] = -1;
    else 
      dp1[0][i] = dp1[0][i - 1] + grid[0][i], path[0][i] = LEFT;

    if (grid[i][0] == -1 || dp1[i - 1][0] == -1)
      dp1[i][0] = -1;
    else
      dp1[i][0] = dp1[i - 1][0] + grid[i][0], path[i][0] = TOP;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (grid[i][j] == -1 || (dp1[i - 1][j] == -1 && dp1[i][j - 1] == -1)) 
        dp1[i][j] = -1;
      else {
        int left = dp1[i][j - 1];
        int top = dp1[i - 1][j];
        if (left >= top) 
          dp1[i][j] = left + grid[i][j], path[i][j] = LEFT;
        else
          dp1[i][j] = top + grid[i][j], path[i][j] = TOP;
      }
    }
  }
  if (dp1[n - 1][n - 1] == -1) return 0;
  int x = n - 1, y = n - 1;
  while (x != 0 || y != 0) {
    grid[x][y] = 0;
    int op = path[x][y];
    if (op == LEFT) {
      y--;
    } else if (op == TOP) {
      x--;
    } else {
      cout << "wrong value in path" << endl;
    }
  }
  grid[0][0] = 0;
  
  dp2[0][0] = grid[0][0];
  for (int i = 1; i < n; i++) {
    if (grid[0][i] == -1 || dp2[0][i - 1] == -1) 
      dp2[0][i] = -1;
    else 
      dp2[0][i] = dp2[0][i - 1] + grid[0][i];

    if (grid[i][0] == -1 || dp2[i - 1][0] == -1)
      dp2[i][0] = -1;
    else
      dp2[i][0] = dp2[i - 1][0] + grid[i][0];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (grid[i][j] == -1 || (dp2[i - 1][j] == -1 && dp2[i][j - 1] == -1)) 
        dp2[i][j] = -1;
      else {
        int left = dp2[i][j - 1];
        int top = dp2[i - 1][j];
        if (left >= top) 
          dp2[i][j] = left + grid[i][j];
        else
          dp2[i][j] = top + grid[i][j];
      }
    }
  }
  return dp1[n - 1][n - 1] + dp2[n - 1][n - 1];
}

int main() {
  return 0;
}
