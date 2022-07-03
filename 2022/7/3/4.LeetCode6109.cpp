/*************************************************************************
	> File Name: 4.LeetCode6109.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月03日 星期日 11时00分22秒
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

long MOD = 1e9 + 7;

int peopleAwareOfSecret(int n, int delay, int forget) {
  vector<long> dp(n + 1, 0);
  dp[1] = 1;
  for (int i = 2; i <= delay; i++) dp[i] = 0;
  for (int i = delay + 1; i <= n; i++) {
    int left = max(0, i - forget + 1);
    for (int j = left; j <= i - delay; j++) dp[i] = (dp[i] + dp[j]) % MOD;
  }
  long ans = 0;
  int left = max(0, n - forget + 1);
  for (int i = left; i <= n; i++) ans = (ans + dp[i]) % MOD;
  return ans;
}

int main() {
  return 0;
}
