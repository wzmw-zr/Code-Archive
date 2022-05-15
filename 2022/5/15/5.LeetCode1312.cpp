/*************************************************************************
	> File Name: 5.LeetCode1312.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月15日 星期日 18时15分23秒
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

int minInsertions(string s) {
  int n = s.size();
  int dp[n][n];
  memset(dp, 0, sizeof(dp));
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i + l - 1 < n; i++) {
      dp[i][i + l - 1] = min(dp[i + 1][i + l - 1], dp[i][i + l - 2]) + 1;
      if (s[i] == s[i + l - 1])
        dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i + 1][i + l - 2]);
    }
  }
  return dp[0][n - 1];
}

int main() {
  return 0;
}
