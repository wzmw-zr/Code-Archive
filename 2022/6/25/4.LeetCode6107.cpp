/*************************************************************************
	> File Name: 4.LeetCode6107.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月25日 星期六 22时56分18秒
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

// WA
long MOD = 1e9 + 7;

int distinctSequences(int n) {
  unordered_map<int, vector<int>> rel_prime(
    {
      {1, {2, 3, 4, 5, 6}},
      {2, {1, 3, 5}},
      {3, {1, 2, 4, 5}},
      {4, {1, 3, 5}},
      {5, {1, 2, 3, 4, 6}},
      {6, {1, 5}},
    }
  );
  long dp[n + 1][7];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= 6; i++) dp[1][i] = 1;
  for (int i = 1; i <= 6; i++) {
    for (auto p : rel_prime[i]) dp[2][i] += dp[1][p];
  }
  for (int i = 3; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      for (auto p1 : rel_prime[j]) {
        for (auto p2 : rel_prime[p1]) {
          if (p2 == j) continue;
          dp[i][j] = (dp[i][j] + dp[i - 2][p2]) % MOD;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 6; i++) ans = (ans + dp[n][i]) % MOD;
  return ans;
}

int main() {
  return 0;
}
