/*************************************************************************
	> File Name: 2.LeetCode634.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月30日 星期五 14时24分18秒
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

int findDerangement(int n) {
  long dp[n + 10];
  memset(dp, 0, sizeof(dp));
  dp[2] = 1;
  for (long i = 3; i <= n; i++)
    dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
  return dp[n];
}

int main() {
  return 0;
}
