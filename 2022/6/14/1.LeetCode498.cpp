/*************************************************************************
	> File Name: 1.LeetCode498.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月14日 星期二 09时12分53秒
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

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size();
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    vector<int> temp;
    int len = min(i + 1, n);
    for (int l = 0; l < len; l++) {
      temp.push_back(mat[i - l][l]);
    }
    if (i & 1) reverse(temp.begin(), temp.end());
    for (int x : temp) ans.push_back(x);
  }
  for (int i = 1; i < n; i++) {
    vector<int> temp;
    int len = min(n - i, m);
    for (int l = 0; l < len; l++) {
      temp.push_back(mat[m - 1 - l][i + l]);
    }
    if (((m + i) & 1) == 0) reverse(temp.begin(), temp.end());
    for (int x : temp) ans.push_back(x);
  }
  return ans;
}

int main() {
  return 0;
}
