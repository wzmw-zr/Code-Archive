/*************************************************************************
	> File Name: 3.LeetCode1425.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月23日 星期四 17时08分10秒
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

int constrainedSubsetSum(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> dp(n, INT32_MIN);
  deque<int> que;
  for (int i = 0; i < n; i++) {
    while (!que.empty() && (i - que.front()) > k)
      que.pop_front();
    dp[i] = nums[i] + (que.empty() ? 0 : max(0, dp[que.front()]));
    while (!que.empty() && dp[que.back()] < dp[i])
      que.pop_back();
    que.push_back(i);
  }
  return *max_element(dp.begin(), dp.end());
}

int main() {
  return 0;
}
