/*************************************************************************
	> File Name: 3.LeetCode1223.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月09日 星期五 14时36分38秒
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
      for (int k = 1; k <= min(rollMax[j - 1], i); k++) {
        for (int p = 1; p <= 6; p++) {
          if (i - k > 0) {
            dp[i][j] = (dp[i][j] + (p == j ? 0 : dp[i - k][p])) % MOD;
          } else if (i - k == 0) {
            dp[i][j] = (dp[i][j] + (p == j ? 1 : 0)) % MOD;
          }
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
