/*************************************************************************
	> File Name: 2.LeetCode6890.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年06月18日 星期日 10时37分34秒
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

int findValueOfPartition(vector<int>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int ans = INT32_MAX;
  for (int i = 0; i < n - 1; i++)
    ans = min(ans, nums[i + 1] - nums[i]);
  return ans;
}

int main() {
  return 0;
}
