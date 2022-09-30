/*************************************************************************
	> File Name: 1.LeetCode2690.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月30日 星期五 08时59分21秒
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

void setZeroes(vector<vector<int>>& matrix) {
  int m = matrix.size();
  if (m == 0)
    return ;
  int n = matrix[0].size();
  if (n == 0)
    return ;
  vector<int> rows(m, 0);
  vector<int> cols(n, 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!matrix[i][j]) 
        rows[i] = 1, cols[j] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (!rows[i])
      continue;
    for (int j = 0; j < n; j++) 
      matrix[i][j] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (!cols[i])
      continue;
    for (int j = 0; j < m; j++)
      matrix[j][i] = 0;
  }
  return ;
}

int main() {
  return 0;
}
