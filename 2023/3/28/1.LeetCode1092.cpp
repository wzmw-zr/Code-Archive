/*************************************************************************
	> File Name: 1.LeetCode1092.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月28日 星期二 09时51分16秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string shortestCommonSupersequence(string str1, string str2) {
  int n = str1.size(), m = str2.size();
  int dp[n + 1][m + 1];
  int pre[n + 1][m + 1][2];
  memset(dp, 0, sizeof(dp));
  memset(pre, 0, sizeof(pre));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i + 1][j] > dp[i][j + 1]) {
        dp[i + 1][j + 1] = dp[i + 1][j];
        pre[i + 1][j + 1][0] = pre[i + 1][j][0];
        pre[i + 1][j + 1][1] = pre[i + 1][j][1];
      } else {
        dp[i + 1][j + 1] = dp[i][j + 1];
        pre[i + 1][j + 1][0] = pre[i][j + 1][0];
        pre[i + 1][j + 1][1] = pre[i][j + 1][1];
      }
      if (str1[i] == str2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
        pre[i + 1][j + 1][0] = i + 1;
        pre[i + 1][j + 1][1] = j + 1;
      }
    }
  }

  vector<int> pos1, pos2;
  int x = n, y = m;
  while (x != 0 && y != 0) {
    if (pre[x][y][0] == x && pre[x][y][1] == y) {
      pos1.push_back(x - 1);
      pos2.push_back(y - 1);
      x--, y--;
    }
    int x_t = pre[x][y][0];
    int y_t = pre[x][y][1];
    x = x_t, y = y_t;
  }
  reverse(pos1.begin(), pos1.end());
  reverse(pos2.begin(), pos2.end());

  x = 0, y = 0;
  string ans = "";
  for (int i = 0; i < pos1.size(); i++) {
    while (x < pos1[i])
      ans += str1[x++];
    while (y < pos2[i])
      ans += str2[y++];
    ans += str1[x];
    x++, y++;
  }
  while (x < n)
    ans += str1[x++];
  while (y < m)
    ans += str2[y++];
  return ans;
}


int main() {
  return 0;
}
