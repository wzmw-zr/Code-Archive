/*************************************************************************
	> File Name: 4.LeetCode6099.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月19日 星期日 15时26分52秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int longestSubsequence(string s, int k) {
  int n = s.size();
  long dp[n][31];
  memset(dp, 0x3f, sizeof(dp));
  dp[n - 1][0] = 0;
  dp[n - 1][1] = s[n - 1] - '0';
  for (int i = 0; i < n; i++) dp[i][0] = 0;
  for (int i = n - 2; i >= 0; i--) {
    long val = s[i] - '0';
    dp[i][1] = min(dp[i + 1][1], val);
    for (int j = 2; j <= 30; j++) {
      dp[i][j] = min(dp[i + 1][j], dp[i + 1][j - 1] + val * (long) pow(2, j - 1));
    }
  }
  int pre[n];
  memset(pre, 0, sizeof(pre));
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1];
    if (s[i - 1] == '0') pre[i]++;
  }
  int ans = pre[n - 1] + (s[n - 1] == '0' ? 1 : 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 30; j++) {
      if (dp[i][j] <= k) 
        ans = max(ans, pre[i] + j);
    }
  }
  return ans;
}

int main() {
  return 0;
}
