/*************************************************************************
	> File Name: 3.LeetCode6238.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月12日 星期六 22时42分31秒
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
int countGoodStrings(int low, int high, int zero, int one) {
  vector<long> dp(high + 10, 0);
  dp[zero] += 1;
  dp[one] += 1;
  for (int i = 1; i <= high; i++) {
    if (i > zero)
      dp[i] = (dp[i] + dp[i - zero]) % MOD;
    if (i > one)
      dp[i] = (dp[i] + dp[i - one]) % MOD;
  }
  long ans = 0;
  for (int i = low; i <= high; i++)
    ans = (ans + dp[i]) % MOD;
  return ans;
}

int main() {
  return 0;
}
