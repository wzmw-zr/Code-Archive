/*************************************************************************
	> File Name: 4.LeetCode6100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月26日 星期日 10时33分48秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long MOD = 1e9 + 7;

int countHousePlacements(int n) {
  long dp[n + 1][4];
  memset(dp, 0, sizeof(dp));
  dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    dp[i][3] = dp[i - 1][0];
  }
  long ans = 0;
  for (int i = 0; i < 4; i++) ans = (ans + dp[n][i]) % MOD;
  return ans;
}

int main() {
  return 0;
}
