/*************************************************************************
	> File Name: 6.LeetCode6195.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月02日 星期日 17时09分10秒
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
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

// WA
long MOD = 1e9 + 7;
long BASE = 233;

int deleteString(string s) {
  int n = s.size();
  vector<long> base(n + 1, 1);
  vector<long> vals(n + 1, 0);
  for (int i = 0; i < n; i++)
    base[i + 1] = base[i] * BASE % MOD;
  for (int i = 0; i < n; i++)
    vals[i + 1] = (vals[i] * BASE + s[i]) % MOD;
  vector<long> dp(n + 1, 1);
  dp[0] = 0;
  long ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int len = i - j + 1;
      if (i + len >= n)
        continue;
      long val_1 = ((vals[i + 1] - vals[i + 1 - len] * base[len]) % MOD + MOD) % MOD;
      long val_2 = ((vals[i + 1 + len] - vals[i + 1] * base[len]) % MOD + MOD) % MOD;
      if (val_1 == val_2)
        dp[i + 1] = max(dp[i + 1], dp[i + 1 - len] + 1);
      ans = max(ans, dp[i + 1] + (i == (n - 1) ? 0 : 1));
    }
  }
  return ans;
}

int main() {
  return 0;
}
