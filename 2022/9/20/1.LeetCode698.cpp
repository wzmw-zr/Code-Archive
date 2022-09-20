/*************************************************************************
	> File Name: 1.LeetCode698.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月20日 星期二 09时18分09秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool canPartitionKSubsets(vector<int>& nums, int k) {
  int n = nums.size();
  int all_sum = 0;
  for (int x : nums) all_sum += x;
  if (all_sum % k)
    return false;
  int avg = all_sum /= k;
  vector<int> sum(1 << n, 0);
  for (int i = 1; i < (1 << n); i++) {
    int cnt = __builtin_ctz(i);
    sum[i] = sum[i - (1 << cnt)] + nums[cnt];
  }
  unordered_map<int, int> mp;
  function<bool(int)> dfs = [&](int state) -> bool {
    if (state == 0)
      return true;
    if (sum[state] == avg)
      return true;
    if (mp.count(state))
      return mp[state];
    bool ans = false;
    for (int i = state - 1; i > 0; i = (i - 1) & state) {
      if (sum[i] != avg)
        continue;
      ans |= dfs(state - i);
    }
    return mp[state] = ans;
  };
  return dfs((1 << n) - 1);
}

int main() {
  return 0;
}
