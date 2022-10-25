/*************************************************************************
	> File Name: 2.LeetCode2448.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月25日 星期二 15时31分40秒
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

using PII = pair<int, int>;

long long minCost(vector<int>& nums, vector<int>& cost) {
  int n = nums.size();
  long total_cost = 0;
  vector<PII> vals;
  for (int i = 0; i < n; i++) {
    vals.push_back(PII(nums[i], cost[i]));
    total_cost += cost[i];
  }
  sort(vals.begin(), vals.end());
  long mid = (total_cost + 1) / 2;
  long cur_cost = 0;
  int target = 0;
  for (int i = 0; i < n; i++) {
    cur_cost += vals[i].second;
    if (cur_cost >= mid) {
      target = vals[i].first;
      break;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) 
    ans += 1L * abs(target - nums[i]) * cost[i];
  return ans;
}

int main() {
  return 0;
}
