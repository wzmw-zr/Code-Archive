/*************************************************************************
	> File Name: 1.LeetCode1223.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月10日 星期五 14时34分29秒
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

int dieSimulator(int n, vector<int>& rollMax) {
  long dp[n + 1][7];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      for (int k = 1; k <= min(i, rollMax[j - 1]); k++) {
        if (i == k) {
          dp[i][j] = (dp[i][j] + 1) % MOD;
          continue;
        }
        for (int p = 1; p <= 6; p++) {
          if (p == j)
            continue;
          dp[i][j] = (dp[i][j] + dp[i - k][p]) % MOD;
        }
      }
    }
  }
  long ans = 0;
  for (int i = 1; i <= 6; i++)
    ans = (ans + dp[n][i]) % MOD;
  return ans;
}

int main() {
  return 0;
}
