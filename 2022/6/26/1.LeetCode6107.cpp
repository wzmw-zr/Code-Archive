/*************************************************************************
	> File Name: 1.LeetCode6107.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月26日 星期日 09时08分21秒
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

int distinctSequences(int n) {
  if (n == 1) return 6;
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
  long dp[n + 1][7][7];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= 6; i++) {
    for (int p : rel_prime[i]) 
      dp[2][i][p] = 1;
  }
  for (int i = 3; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      for (int p_1 : rel_prime[j]) {
        for (int p_2 : rel_prime[p_1]) {
          if (p_2 == j) continue;
          dp[i][j][p_1] = (dp[i][j][p_1] + dp[i - 1][p_1][p_2]) % MOD;
        }
      }
    }
  }
  long ans = 0;
  for (int i = 1; i <= 6; i++) {
    for (int p : rel_prime[i]) ans = (ans + dp[n][i][p]) % MOD;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << distinctSequences(n) << endl;
  return 0;
}
