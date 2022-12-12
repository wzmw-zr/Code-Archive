/*************************************************************************
	> File Name: 1.LeetCode1781.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月12日 星期一 10时12分49秒
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

int beautySum(string s) {
  int n = s.size();
  int dp[n + 1][26];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    memcpy(dp[i + 1], dp[i], sizeof(dp[i + 1]));
    dp[i + 1][s[i] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int mmax = INT32_MIN, mmin = INT32_MAX;
      for (int k = 0; k < 26; k++) {
        if (dp[j + 1][k] != dp[i][k]) {
          mmax = max(mmax, dp[j + 1][k] - dp[i][k]);
          mmin = min(mmin, dp[j + 1][k] - dp[i][k]);
        }
      }
      ans += mmax - mmin;
    }
  }
  return ans;
}

int main() {
  return 0;
}
