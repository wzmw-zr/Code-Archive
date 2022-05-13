/*************************************************************************
	> File Name: 2.LeetCode730.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月13日 星期五 10时20分21秒
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

long MOD = 1e9 + 7;

int countPalindromicSubsequences(string s) {
  int n = s.size();
  long dp[n][n][4];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) dp[i][i][s[i] - 'a'] = 1;
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i + l - 1 < n; i++) {
      for (int j = 0; j < 4; j++) {
        if (s[i] - 'a' != j) 
          dp[i][i + l - 1][j] = dp[i + 1][i + l - 1][j];
        if (s[i + l - 1] - 'a' != j) 
          dp[i][i + l - 1][j] = dp[i][i + l - 2][j];
        if (s[i] == s[i + l - 1] && s[i] - 'a' == j) {
          dp[i][i + l - 1][j] = 2; 
          for (int k = 0; k < 4; k++) 
            dp[i][i + l - 1][j] = (dp[i][i + l - 1][j] + dp[i + 1][i + l - 2][k]) % MOD;
        }
      }
    }
  }
  long ans = 0;
  for (int i = 0; i < 4; i++) ans = (ans + dp[0][n - 1][i]) % MOD;
  return ans;
}

int main() {
  return 0;
}
