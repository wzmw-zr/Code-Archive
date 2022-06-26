/*************************************************************************
	> File Name: 3.LeetCode6101.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月26日 星期日 10时30分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool checkXMatrix(vector<vector<int>>& grid) {
  int n = grid.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || (i + j == n - 1)) {
        if (!grid[i][j]) return false;
      } else {
        if (grid[i][j]) return false;
      }
    }
  }
  return true;
}

int main() {
  return 0;
}
