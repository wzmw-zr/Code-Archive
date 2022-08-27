/*************************************************************************
	> File Name: 2.LeetCode2386.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月27日 星期六 16时16分39秒
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

using PLI = pair<long, int>;

long long kSum(vector<int>& nums, int k) {
  long long negative = 0;
  long long sum = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    negative += nums[i] >= 0 ? 0 : nums[i];
    sum += abs(nums[i]);
    nums[i] = abs(nums[i]);
  }
  sort(nums.begin(), nums.end());
  priority_queue<PLI, vector<PLI>, greater<PLI>> que;
  que.push(PLI(nums[0], 0));
  long long k_min = 0;
  for (int i = 1; i < k; i++) {
    auto temp = que.top();
    que.pop();
    auto [val, ind] = temp;
    k_min = val;
    if (ind == n - 1) continue;
    que.push(PLI(val + nums[ind + 1], ind + 1));
    que.push(PLI(val - nums[ind] + nums[ind + 1], ind + 1));
  }
  long long ans = sum - k_min + negative;
  return ans;
}

int main() {
  return 0;
}
