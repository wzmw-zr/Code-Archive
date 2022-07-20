/*************************************************************************
	> File Name: 1.LeetCode1260.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月20日 星期三 09时47分25秒
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

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
  int m = grid.size(), n = grid[0].size();
  for (int i = 0; i < k; i++) {
    vector<vector<int>> temp(m, vector<int>(n));
    for (int p = 0; p < n - 1; p++) {
      for (int q = 0; q < m; q++) {
        temp[q][p + 1] = grid[q][p];
      }
    }
    temp[0][0] = grid[m - 1][n - 1];
    for (int p = 0; p < m - 1; p++) 
      temp[p + 1][0] = grid[p][n - 1];
    grid = temp;
  }
  return grid;
}

int main() {
  return 0;
}
