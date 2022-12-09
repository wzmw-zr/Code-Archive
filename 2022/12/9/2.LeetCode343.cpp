/*************************************************************************
	> File Name: 2.LeetCode343.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月09日 星期五 10时09分35秒
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

int cuttingRope(int n) {
  int dp[n + 5];
  memset(dp, 0, sizeof(dp));
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int k = 1; k <= i - 1; k++) {
      dp[i] = max(dp[i], max(i - k, dp[i - k]) * k);
    }
  }
  return dp[n];
}

int main() {
  return 0;
}
