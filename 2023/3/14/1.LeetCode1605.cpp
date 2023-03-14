/*************************************************************************
	> File Name: 1.LeetCode1605.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月14日 星期二 20时38分27秒
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

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
  int n = rowSum.size(), m = colSum.size();
  vector<vector<int>> ans(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int val = min(rowSum[i], colSum[j]);
      ans[i][j] = val;
      rowSum[i] -= val;
      colSum[j] -= val;
    }
  }
  return ans;
}

int main() {
  return 0;
}
