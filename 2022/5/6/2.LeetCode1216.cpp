/*************************************************************************
	> File Name: 2.LeetCode1216.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月06日 星期五 10时38分27秒
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

bool isValidPalindrome(string s, int k) {
  int n = s.size();
  int dp[n][n];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) dp[i][i] = 1;
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i + l - 1 < n; i++) {
      if (s[i] == s[i + l - 1]) dp[i][i + l - 1] = dp[i + 1][i + l - 2] + 2;
      dp[i][i + l - 1] = max({dp[i][i + l - 1], dp[i + 1][i + l - 1], dp[i][i + l - 2]});
    }
  }
  return (n - dp[0][n - 1]) <= k;
}

int main() {
  return 0;
}
