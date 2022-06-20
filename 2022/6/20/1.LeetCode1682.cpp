/*************************************************************************
	> File Name: 1.LeetCode1682.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月20日 星期一 14时09分55秒
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

int longestPalindromeSubseq(string s) {
  int n = s.size();
  int dp[n][n][26];
  memset(dp, 0, sizeof(dp));
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i + l - 1 < n; i++) {
      for (int x = 0; x < 26; x++)
        dp[i][i + l - 1][x] = max({dp[i][i + l - 1][x], dp[i + 1][i + l - 1][x], dp[i][i + l - 2][x]});
      if (s[i] == s[i + l - 1]) {
        int ind = s[i] - 'a';
        int mmax = 0;
        for (int x = 0; x < 26; x++) {
          if (x == ind) continue;
          mmax = max(mmax, dp[i + 1][i + l - 2][x]);
        }
        dp[i][i + l - 1][ind] = max({dp[i][i + l - 1][ind], mmax + 2, dp[i + 1][i + l - 2][ind]});
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) ans = max(ans, dp[0][n - 1][i]);
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << longestPalindromeSubseq(s) << endl;
  return 0;
}
