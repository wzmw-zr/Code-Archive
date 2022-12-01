/*************************************************************************
	> File Name: 1.LeetCode1779.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月01日 星期四 09时51分13秒
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

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
  int mmin = INT32_MAX;
  int n = points.size();
  for (auto && p : points) {
    if (x == p[0]) 
      mmin = min(mmin, abs(y - p[1]));
    if (y == p[1])
      mmin = min(mmin, abs(x - p[0]));
  }
  if (mmin == INT32_MAX)
    return -1;
  for (int i = 0; i < n; i++) {
    if (x == points[i][0] && abs(y - points[i][1]) == mmin)
      return i;
    if (y == points[i][1] && abs(x - points[i][0]) == mmin)
      return i;
  }
  return -1;
}

int main() {
  return 0;
}
