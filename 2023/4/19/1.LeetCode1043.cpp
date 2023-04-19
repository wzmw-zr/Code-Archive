/*************************************************************************
	> File Name: 1.LeetCode1043.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月19日 星期三 09时28分05秒
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

int maxSumAfterPartitioning(vector<int>& arr, int k) {
  int n = arr.size();
  int mmax[n + 1][n + 1];
  int dp[n + 1];
  memset(mmax, 0, sizeof(mmax));
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    int val = 0;
    for (int j = i; j <= n; j++) {
      val = max(val, arr[j - 1]);
      mmax[i][j] = val;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(k, i); j++)
      dp[i] = max(dp[i], dp[i - j] + mmax[i - j + 1][i] * j);
  }
  return dp[n];
}

int main() {
  return 0;
}
