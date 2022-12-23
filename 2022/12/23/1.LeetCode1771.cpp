/*************************************************************************
	> File Name: 1.LeetCode1771.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月23日 星期五 10时44分38秒
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

int longestPalindrome(string word1, string word2) {
  int m = word1.size();
  string s = word1 + word2;
  int n = s.size();
  int dp[n][n];
  int ans = 0;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++)
    dp[i][i] = 1;
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i + l - 1 < n; i++) {
      dp[i][i + l - 1] = max(dp[i][i + l - 2], dp[i + 1][i + l - 1]);
      if (s[i] == s[i + l - 1]) {
        if ((dp[i + 1][i + l - 2] + 2) >= dp[i][i + l - 1] && i < m && (i + l - 1) >= m)
          ans = max(ans, dp[i + 1][i + l - 2] + 2);
        dp[i][i + l - 1] = max(dp[i][i + l - 1], dp[i + 1][i + l - 2] + 2);
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
