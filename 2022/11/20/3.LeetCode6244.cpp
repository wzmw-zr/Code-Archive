/*************************************************************************
	> File Name: 3.LeetCode6244.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月20日 星期日 10时48分56秒
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

// TLE
long MOD = 1e9 + 7;

int beautifulPartitions(string s, int k, int minLength) {
  int n = s.size();
  long dp[n + 1][k + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  unordered_set<int> primes = {2, 3, 5, 7};
  for (int i = minLength - 1; i < n; i++) {
    int x = s[i] - '0';
    if (primes.count(x))
      continue;
    for (int j = 0; j <= i - minLength + 1; j++) {
      int y = s[j] - '0';
      if (!primes.count(y))
        continue;
      for (int p = 1; p <= k; p++)
        dp[i + 1][p] = (dp[i + 1][p] + dp[j][p - 1]) % MOD;
    }
  }
  return dp[n][k];
}

int main() {
  return 0;
}
