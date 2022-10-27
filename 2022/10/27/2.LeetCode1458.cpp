/*************************************************************************
	> File Name: 2.LeetCode1458.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月27日 星期四 23时34分07秒
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

// WA
int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size(), m = nums2.size();
  vector<vector<int>> dp(n, vector<int>(m, INT32_MIN));
  for (int i = 0; i < m; i++)
    dp[0][i] = nums1[0] * nums2[i];
  for (int i = 0; i < n; i++)
    dp[i][0] = nums1[i] * nums2[0];
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + nums1[i] * nums2[j]});
    }
  }
  return dp[n - 1][m - 1];
}

int main() {
  return 0;
}
