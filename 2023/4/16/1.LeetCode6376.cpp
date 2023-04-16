/*************************************************************************
	> File Name: 1.LeetCode6376.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月16日 星期日 10时30分38秒
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

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size();
  vector<int> cnts(m, 0);
  int mmax = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      cnts[i] += mat[i][j];
    mmax = max(mmax, cnts[i]);
  }
  for (int i = 0; i < m; i++) {
    if (cnts[i] == mmax)
      return {i, cnts[i]};
  }
  return {0, 0};
}

int main() {
  return 0;
}
