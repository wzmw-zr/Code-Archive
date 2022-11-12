/*************************************************************************
	> File Name: 1.LeetCode790.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月12日 星期六 09时15分16秒
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

int numTilings(int n) {
  vector<long> dp(n + 5, 0);
  dp[1] = 1, dp[2] = 2, dp[3] = 5, dp[4] = 11;
  for (int i = 5; i <= n; i++) {
    long sum = (2 + dp[i - 1] + dp[i - 2]) % MOD;
    for (int j = 3; j < i; j++)
      sum = (sum + dp[i - j] * 2) % MOD;
    dp[i] = sum;
  }
  return dp[n];
}

int main() {
  return 0;
}
