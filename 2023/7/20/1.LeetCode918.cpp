/*************************************************************************
	> File Name: 1.LeetCode918.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月20日 星期四 09时20分40秒
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
#include <functional>
#include <cstdint>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++)
    nums.push_back(nums[i]);
  vector<int> pre_sum(2 * n + 1, 0);
  for (int i = 0; i < 2 * n; i++)
    pre_sum[i + 1] = pre_sum[i] + nums[i];
  function<bool(int, int)> cmp = [&](int x, int y) -> bool {
    return pre_sum[x] == pre_sum[y] ? x > y : pre_sum[x] > pre_sum[y];
  };
  priority_queue<int, vector<int>, decltype(cmp)> que(cmp);
  que.push(0);
  int ans = INT32_MIN;
  for (int i = 1; i <= 2 * n; i++) {
    while (!que.empty() && que.top() < (i - n))
      que.pop();
    ans = max(ans, pre_sum[i] - pre_sum[que.top()]);
    que.push(i);
  }
  return ans;
}

int main() {
  return 0;
}
