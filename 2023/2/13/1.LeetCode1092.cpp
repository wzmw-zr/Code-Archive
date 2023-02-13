/*************************************************************************
	> File Name: 1.LeetCode1092.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月13日 星期一 09时45分05秒
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

using PII = pair<int, int>;

string shortestCommonSupersequence(string str1, string str2) {
  int n = str1.size(), m = str2.size();
  int dp[n + 1][m + 1], pos[n + 1][m + 1][2];
  memset(dp, 0, sizeof(dp));
  memset(pos, 0, sizeof(pos));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i + 1][j + 1] = dp[i][j + 1];
      pos[i + 1][j + 1][0] = pos[i][j + 1][0];
      pos[i + 1][j + 1][1] = pos[i][j + 1][1];
      if (dp[i + 1][j] > dp[i + 1][j + 1]) {
        dp[i + 1][j + 1] = dp[i + 1][j];
        pos[i + 1][j + 1][0] = pos[i + 1][j][0];
        pos[i + 1][j + 1][1] = pos[i + 1][j][1];
      }
      if (str1[i] == str2[j] && (dp[i][j] + 1) > dp[i + 1][j + 1]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
        pos[i + 1][j + 1][0] = i + 1;
        pos[i + 1][j + 1][1] = j + 1;
      }
    }
  }
  vector<PII> inds;
  int x = n, y = m;
  while (x && y) {
    if (x == pos[x][y][0] && y == pos[x][y][1]) {
      inds.push_back(PII(x - 1, y - 1));
      x--, y--;
    }
    int x_t = pos[x][y][0], y_t = pos[x][y][1];
    x = x_t, y = y_t;
  }
  reverse(inds.begin(), inds.end());
  x = 0, y = 0;
  string ans = "";
  for (auto && ind : inds) {
    int x_t = ind.first, y_t = ind.second;
    while (x < x_t)
      ans += str1[x++];
    while (y < y_t)
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
  string str1, str2;
  cin >> str1 >> str2;
  cout << shortestCommonSupersequence(str1, str2) << endl;
  return 0;
}
