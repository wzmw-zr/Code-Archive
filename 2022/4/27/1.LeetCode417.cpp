/*************************************************************************
	> File Name: 1.LeetCode417.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月27日 星期三 11时58分07秒
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

using PII = pair<int, int>;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
  int m = matrix.size(), n = matrix[0].size();
  vector<vector<int>> check1(m, vector<int>(n, 0));
  vector<vector<int>> check2(m, vector<int>(n, 0));
  queue<PII> que;
  for (int i = 0; i < n; i++) que.push(PII(0, i));
  for (int i = 0; i < m; i++) que.push(PII(i, 0));
  while (!que.empty()) {
    auto temp = que.front();
    que.pop();
    if (check1[temp.first][temp.second]) continue;
    check1[temp.first][temp.second] = 1;
    for (int i = 0; i < 4; i++) {
      int x = temp.first + dir[i][0];
      int y = temp.second + dir[i][1];
      if (x < 0 || x >= m || y < 0 || y >= n || check1[x][y]) continue;
      if (matrix[x][y] >= matrix[temp.first][temp.second]) 
        que.push(PII(x, y));
    }
  }

  for (int i = 0; i < n; i++) que.push(PII(m - 1, i));
  for (int i = 0; i < m; i++) que.push(PII(i, n - 1));
  while (!que.empty()) {
    auto temp = que.front();
    que.pop();
    if (check2[temp.first][temp.second]) continue;
    check2[temp.first][temp.second] = 1;
    for (int i = 0; i < 4; i++) {
      int x = temp.first + dir[i][0];
      int y = temp.second + dir[i][1];
      if (x < 0 || x >= m || y < 0 || y >= n || check2[x][y]) continue;
      if (matrix[x][y] >= matrix[temp.first][temp.second]) 
        que.push(PII(x, y));
    }
  }
  vector<vector<int>> ans;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (check1[i][j] && check2[i][j]) ans.push_back({i, j});
    }
  }
  return ans;
}

int main() {
  return 0;
}
