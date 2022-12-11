/*************************************************************************
	> File Name: 1.LeetCode6257.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月11日 星期日 10时31分56秒
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

int deleteGreatestValue(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  for (int i = 0; i < m; i++)
    sort(grid[i].begin(), grid[i].end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int mmax = INT32_MIN;
    for (int j = 0; j < m; j++)
      mmax = max(mmax, grid[j][i]);
    ans += mmax;
  }
  return ans;
}

int main() {
  return 0;
}
