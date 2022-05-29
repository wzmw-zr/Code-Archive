/*************************************************************************
	> File Name: 4.LeetCode6080.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月29日 星期日 11时02分43秒
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
int bs_last_le(vector<int> &nums, int max_len, int target) {
  int l = 0, r = max_len;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (nums[mid] <= target) l = mid;
    else r = mid - 1;
  }
  return l;
}

int totalSteps(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n, 1);
  vector<int> len(n + 1, INT32_MAX);
  int max_len = 0;
  for (int i = 0; i < n; i++) {
    int ind = bs_last_le(len, max_len, nums[i]);
    dp[i] = ind + 1;
    len[ind + 1] = min(len[ind + 1], nums[i]);
    max_len = max(max_len, ind + 1);
  }
  int mmax = 0;
  for (int i = 0; i < n; i++) mmax = max(mmax, dp[i]);
  return n - mmax;
}

int main() {
  return 0;
}
