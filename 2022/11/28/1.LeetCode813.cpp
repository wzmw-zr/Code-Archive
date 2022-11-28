/*************************************************************************
	> File Name: 1.LeetCode813.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月28日 星期一 09时38分34秒
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

// WA
double largestSumOfAverages(vector<int>& nums, int k) {
  int n = nums.size();
  double pre[n + 1];
  double dp[n + 1][n + 1];
  memset(pre, 0, sizeof(pre));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) 
    pre[i + 1] = pre[i] + nums[i];
  for (int i = 0; i < n; i++)
    dp[i + 1][1] = (pre[i + 1] - pre[0]) / (i + 1);
  double ans = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      for (int p = i; p <= j - 1; p++) {
        double val = (pre[j] - pre[p - 1]) / (j - p + 1);
        dp[j][i] = max(dp[j][i], dp[p - 1][i - 1] + val);
        ans = max(ans, dp[j][i]);
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
