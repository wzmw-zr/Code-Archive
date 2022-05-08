/*************************************************************************
	> File Name: 4.LeetCode6058.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月08日 星期日 10时42分15秒
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

long MOD = 1e9 + 7;

int countTexts(string s) {
  vector<long> cnts({0, 0, 3, 3, 3, 3, 3, 4, 3, 4});
  int n = s.size();
  vector<long> dp(n, 0);
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    for (int l = 1; l <= cnts[s[i] - '0']; l++) {
      if (i - l + 1 < 0) break;
      if (s[i - l + 1] != s[i]) break;
      if (i - l + 1 == 0) {
        dp[i] = (dp[i] + 1) % MOD;
      } else {
        dp[i] = (dp[i] + dp[i - l]) % MOD;
      }
    }
  }
  return dp[n - 1];
}

int main() {
  return 0;
}
