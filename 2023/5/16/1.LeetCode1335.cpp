/*************************************************************************
	> File Name: 1.LeetCode1335.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月16日 星期二 09时24分00秒
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

int minDifficulty(vector<int>& jobDifficulty, int d) {
  int n = jobDifficulty.size();
  int dp[n + 1][d + 1];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= d; i++) {
    for (int j = 1; j <= n; j++) {
      int mmax = 0;
      for (int k = j; k >= i; k--) {
        mmax = max(mmax, jobDifficulty[k - 1]);
        dp[j][i] = min(dp[j][i], dp[k - 1][i - 1] + mmax);
      }
    }
  }
  return dp[n][d] == 0x3f3f3f3f ? -1 : dp[n][d];
}

int main() {
  return 0;
}
