/*************************************************************************
	> File Name: 1.LeetCode1139.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月17日 星期五 10时33分36秒
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

// WA
int largest1BorderedSquare(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  for (int len = min(n, m); len >= 1; len--) {
    for (int i = 0; i + len <= n; i++) {
      for (int j = 0; j + len <= m; j++) {
        int flag = 0;
        for (int x = i; x < (i + len); x++) {
          if ((grid[x][j] == 1) && (grid[x][j + len - 1] == 1))
            continue;
          flag = 1;
          break;
        }
        if (flag)
          break;
        for (int y = j; y < (j + len); y++) {
          if ((grid[i][y] == 1) && (grid[i + len - 1][y] == 1))
            continue;
          flag = 1;
          break;
        }
        if (flag)
          break;
        return len * len;
      }
    }
  }
  return 0;
}

int main() {
  return 0;
}
