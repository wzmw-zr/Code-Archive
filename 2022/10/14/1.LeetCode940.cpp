/*************************************************************************
	> File Name: 1.LeetCode940.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月14日 星期五 09时16分10秒
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

const long MOD = 1e9 + 7;

int distinctSubseqII(string s) {
  int n = s.size();
  long dp[n + 1][26];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    long sum = 1;
    for (int j = 0; j < 26; j++) {
      dp[i + 1][j] = dp[i][j];
      sum = (sum + dp[i][j]) % MOD;
    }
    dp[i + 1][s[i] - 'a'] = sum;
  }
  long ans = 0;
  for (int i = 0; i < 26; i++) 
    ans = (ans + dp[n][i]) % MOD;
  return ans;
}

int main() {
  return 0;
}
