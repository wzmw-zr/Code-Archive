/*************************************************************************
	> File Name: 8.LeetCode296.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月02日 星期日 22时27分53秒
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

int minTotalDistance(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<int> arr_x;
  vector<int> arr_y;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j]) {
        arr_x.push_back(i);
        arr_y.push_back(j);
      }
    }
  }
  sort(arr_x.begin(), arr_x.end());
  sort(arr_y.begin(), arr_y.end());
  int k = arr_x.size();
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += abs(arr_x[i] - arr_x[(1 + k) / 2 - 1]);
    ans += abs(arr_y[i] - arr_y[(1 + k) / 2 - 1]);
  }
  return ans;
}

int main() {
  return 0;
}
