/*************************************************************************
	> File Name: 1.LeetCode1458.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月28日 星期五 09时25分31秒
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

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size(), m = nums2.size();
  int dp[n][m];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = nums1[0] * nums2[0];
  for (int i = 1; i < m; i++)
    dp[0][i] = max(dp[0][i - 1], nums1[0] * nums2[i]);
  for (int i = 1; i < n; i++)
    dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
  for (int i = 1; i < n;  i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + nums1[i] * nums2[j], nums1[i] * nums2[j]});
    }
  }
  return dp[n - 1][m - 1];
}

int main() {
  return 0;
}
