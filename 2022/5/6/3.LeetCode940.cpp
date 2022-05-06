/*************************************************************************
	> File Name: 3.LeetCode940.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月06日 星期五 18时44分51秒
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

int distinctSubseqII(string s) {
  int n = s.size();
  long dp[n][26];
  memset(dp, 0, sizeof(dp));
  dp[0][s[0] - 'a'] = 1;
  for (int i = 1; i < n; i++) {
    long sum = 0;
    for (int j = 0; j < 26; j++) sum = (sum + dp[i - 1][j]) % MOD;
    for (int j = 0; j < 26; j++) dp[i][j] = dp[i - 1][j];
    dp[i][s[i] - 'a'] = (sum + 1 + MOD) % MOD;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++)  cout << dp[i][j] << " ";
    cout << endl;
  }
  long ans = 0;
  for (int i = 0; i < 26; i++) ans = (ans + dp[n - 1][i]) % MOD;
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << distinctSubseqII(s) << endl;
  return 0;
}
