/*************************************************************************
	> File Name: 3.LeetCode568.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月03日 星期五 22时03分17秒
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

int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
  int n = flights.size();
  int k = days[0].size();
  int dp[n][k];
  int reach[n][k];
  memset(dp, 0, sizeof(dp));
  memset(reach, 0, sizeof(reach));
  dp[0][0] = days[0][0];
  reach[0][0] = 1;
  for (int i = 1; i < n; i++) {
    if (flights[0][i]) dp[i][0] = days[i][0], reach[i][0] = 1;
  }
  for (int w = 1; w < k; w++) {
    for (int i = 0; i < n; i++) {
      if (reach[i][w - 1]) {
        for (int j = 0; j < n; j++) {
          if (i == j) reach[j][w] = 1;
          else if (flights[i][j]) reach[j][w] = 1;
        }
      }
    }
  }
  for (int w = 1; w < k; w++) {
    for (int i = 0; i < n; i++) {
      int mmax = dp[i][w - 1];
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (flights[j][i]) mmax = max(mmax, dp[j][w - 1]);
      }
      if (reach[i][w]) dp[i][w] = mmax + days[i][w];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i][k - 1]);
  return ans;
}

int main() {
  return 0;
}
