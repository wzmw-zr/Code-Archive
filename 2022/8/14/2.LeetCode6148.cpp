/*************************************************************************
	> File Name: 2.LeetCode6148.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月14日 星期日 10时31分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
  int n = grid.size();
  vector<vector<int>> ans(n - 2, vector<int>(n - 2));
  for (int x = 0; x < n - 2; x++) {
    for (int y = 0; y < n - 2; y++) {
      vector<int> vals;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
          vals.push_back(grid[x + i][y + j]);
      }
      sort(vals.begin(), vals.end());
      ans[x][y] = *vals.rbegin();
    }
  }
  return ans;
}

int main() {
  return 0;
}
