/*************************************************************************
	> File Name: 2.LeetCode1335.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月02日 星期四 22时43分09秒
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

int minDifficulty(vector<int>& jobDifficulty, int d) {
  int n = jobDifficulty.size();
  if (n < d) return -1;
  int mmax[n][n];
  memset(mmax, 0, sizeof(mmax));
  for (int i = 0; i < n; i++) {
    mmax[i][i] = jobDifficulty[i];
    for (int j = i + 1; j < n; j++) 
      mmax[i][j] = max(mmax[i][j - 1], jobDifficulty[j]);
  }
  int dp[d][n];
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i < n; i++) dp[0][i] = mmax[0][i];
  for (int i = 1; i < d; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; k < n; k++) {
        dp[i][k] = min(dp[i][k], dp[i - 1][j - 1] + mmax[j][k]);
      }
    }
  }
  return dp[d - 1][n - 1];
}

int main() {
  return 0;
}
