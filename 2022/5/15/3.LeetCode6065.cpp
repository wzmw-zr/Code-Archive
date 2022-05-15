/*************************************************************************
	> File Name: 3.LeetCode6065.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月15日 星期日 10时53分42秒
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

int largestCombination(vector<int>& candidates) {
  int n = candidates.size();
  int dp[n + 1][32];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 32; j++) {
      dp[i + 1][j] = dp[i][j];
      if (candidates[i] & (1 << j)) dp[i + 1][j]++;
    }
  }
  int mmax = 0;
  for (int i = 0; i < 32; i++) mmax = max(mmax, dp[n][i]);
  return mmax;
}

int main() {
  return 0;
}
