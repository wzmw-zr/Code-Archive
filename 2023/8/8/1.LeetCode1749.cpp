/*************************************************************************
	> File Name: 1.LeetCode1749.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月08日 星期二 09时41分48秒
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

int maxAbsoluteSum(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp1(n + 1, 0);
  vector<int> dp2(n + 1, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp1[i + 1] = max(nums[i], dp1[i] + nums[i]);
    dp2[i + 1] = min(nums[i], dp2[i] + nums[i]);
    ans = max({ans, abs(dp1[i + 1]), abs(dp2[i + 1])});
  }
  return ans;
}

int main() {
  return 0;
}
