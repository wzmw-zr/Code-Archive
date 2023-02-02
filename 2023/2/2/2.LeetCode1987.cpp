/*************************************************************************
	> File Name: 2.LeetCode1987.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月02日 星期四 15时58分58秒
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

int numberOfUniqueGoodSubsequences(string binary) {
  int n = binary.size();
  long dp[n + 1][2];
  memset(dp, 0, sizeof(dp));
  int zero = 0;
  for (int i = 0; i < n; i++) {
    char c = binary[i];
    if (c == '0') {
      zero = 1;
      dp[i + 1][0] = (dp[i][0] + dp[i][1]) % MOD;
      dp[i + 1][1] = dp[i][1];
    } else {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = (1 + dp[i][0] + dp[i][1]) % MOD;
    }
  }
  return (dp[n][0] + dp[n][1] + zero) % MOD;
}

int main() {
  string binary;
  cin >> binary;
  cout << numberOfUniqueGoodSubsequences(binary) << endl;
  return 0;
}
