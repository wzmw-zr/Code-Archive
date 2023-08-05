/*************************************************************************
	> File Name: 2.LeetCode6956.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月05日 星期六 22时45分06秒
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
#include <cstdint>
using namespace std;

int minimumSeconds(vector<int>& nums) {
  int n = nums.size();
  unordered_map<int, int> pre_pos;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    if (!pre_pos.count(nums[i]))
      pre_pos[nums[i]] = i;
    mp[nums[i]] = 0;
  }
  for (int i = 0; i < n; i++)
    nums.push_back(nums[i]);

  for (int i = 0; i < 2 * n; i++) {
    mp[nums[i]] = max(mp[nums[i]], max(0, i - pre_pos[nums[i]] - 1));
    pre_pos[nums[i]] = i;
  }
  int ans = INT32_MAX;
  for (auto && [x, dis] : mp)
    ans = min(ans, dis);
  return (ans + 1) / 2;
}

int main() {
  return 0;
}
