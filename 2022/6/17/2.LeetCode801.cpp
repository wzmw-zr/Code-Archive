/*************************************************************************
	> File Name: 2.LeetCode801.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月17日 星期五 09时26分16秒
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

int minSwap(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  int dp[n][2];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0, dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
      dp[i][0] = min(dp[i][0], dp[i - 1][0]);
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
    }
    if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);
      dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
    }
  }
  return min(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
  return 0;
}
