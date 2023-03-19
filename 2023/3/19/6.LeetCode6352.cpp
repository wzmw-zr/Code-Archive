/*************************************************************************
	> File Name: 6.LeetCode6352.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月19日 星期日 11时24分55秒
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

int beautifulSubsets(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> dp(1 << n, 0);
  for (int i = 1; i < (1 << n); i++) {
    if (__builtin_popcount(i) == 1) {
      dp[i] = 1;
      continue;
    }
    int ind = __builtin_ctz(i);
    int rest = i - (1 << ind);
    if (!dp[rest]) {
      dp[i] = 0;
      continue;
    }
    int flag = 1;
    while (rest) {
      int idx = __builtin_ctz(rest);
      rest -= 1 << idx;
      if (abs(nums[ind] - nums[idx]) == k) {
        flag = 0;
        break;
      }
    }
    dp[i] = flag;
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++)
    ans += dp[i];
  return ans;
}

int main() {
  return 0;
}
