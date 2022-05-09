/*************************************************************************
	> File Name: 2.LeetCode1147.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月09日 星期一 09时05分28秒
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

long base = 233;
long MOD = 1e9 + 7;

// TLE
int longestDecomposition(string s) {
  int n = s.size();
  long hash_val[n][n];
  memset(hash_val, 0, sizeof(hash_val));
  for (int i = 0; i < n; i++) {
    long long val = 0;
    for (int l = 1; l <= n - i; l++) {
      val = (val * base + (s[i + l - 1] - 'a' + 1)) % MOD;
      hash_val[i][i + l - 1] = val;
    }
  }

  int dp[n][n];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) dp[i][i] = 1;
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i + l - 1 < n; i++) {
      dp[i][i + l - 1] = 1;
      for (int j = 1; j <= l / 2; j++) {
        if (hash_val[i][i + j - 1] == hash_val[i + l - j][i + l - 1])
          dp[i][i + l - 1] = max(dp[i][i + l - 1], 2 + dp[i + j][i + l - j - 1]);
      }
    }
  }
  return dp[0][n - 1];
}

int main() {
  string s;
  cin >> s;
  cout << longestDecomposition(s) << endl;
  return 0;
}
