/*************************************************************************
	> File Name: 1.LeetCode6310.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月05日 星期日 10时53分55秒
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

int waysToReachTarget(int target, vector<vector<int>>& types) {
  int n = types.size();
  long dp[n + 1][target + 10];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int num = types[i][0];
    int val = types[i][1];
    for (int j = 0; j <= target; j++) {
      for (int cnt = 0; cnt * val <= j && cnt <= num; cnt++)
        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - cnt * val]) % MOD;
    }
  }
  return dp[n][target];
}

int main() {
  return 0;
}
