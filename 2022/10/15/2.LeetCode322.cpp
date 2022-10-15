/*************************************************************************
	> File Name: 2.LeetCode322.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月15日 星期六 11时02分48秒
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

int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();
  int dp[n + 1][amount + 1];
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= amount; j++) {
      dp[i + 1][j] = dp[i][j];
      if (j >= coins[i])
        dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - coins[i]] + 1);
    }
  }
  return dp[n][amount] == 0x3f3f3f3f ? -1 : dp[n][amount];
}

int main() {
  return 0;
}
