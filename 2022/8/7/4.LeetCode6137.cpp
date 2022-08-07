/*************************************************************************
	> File Name: 4.LeetCode6137.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月07日 星期日 10时43分54秒
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

bool validPartition(vector<int>& nums) {
  int n = nums.size();
  if (n == 2) 
    return nums[0] == nums[1];
  vector<int> dp(n + 1, 0);
  if (nums[0] == nums[1]) 
    dp[1] = 1;
  if (nums[0] == nums[1] && nums[1] == nums[2]) 
    dp[2] = 1;
  if (((nums[0] + 1) == nums[1]) && ((nums[1] + 1) == nums[2])) 
    dp[2] = 1;
  for (int i = 3; i < n; i++) {
    if (nums[i] == nums[i - 1]) 
      dp[i] |= dp[i - 2];
    if (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) 
      dp[i] |= dp[i - 3];
    if ((nums[i] == nums[i - 1] + 1) && (nums[i - 1] == nums[i - 2] + 1))
      dp[i] |= dp[i - 3];
  }
  return dp[n - 1];
}

int main() {
  return 0;
}
