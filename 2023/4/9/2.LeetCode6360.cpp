/*************************************************************************
	> File Name: 2.LeetCode6360.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月09日 星期日 10时38分43秒
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

vector<long long> distance(vector<int>& nums) {
  int n = nums.size();
  vector<long long> ans(n, 0);
  unordered_map<long, long> cnts;
  unordered_map<long, long> sum_of_inds;

  for (int i = 0; i < n; i++) {
    if (!cnts.count(nums[i])) {
      cnts[nums[i]] = 1;
      sum_of_inds[nums[i]] = i;
    } else {
      cnts[nums[i]]++;
      sum_of_inds[nums[i]] += i;
    }
    ans[i] += cnts[nums[i]] * i - sum_of_inds[nums[i]];
  }

  cnts = unordered_map<long, long>();
  sum_of_inds = unordered_map<long, long>();

  for (int i = n - 1; i >= 0; i--) {
    if (!cnts.count(nums[i])) {
      cnts[nums[i]] = 1;
      sum_of_inds[nums[i]] = i;
    } else {
      cnts[nums[i]]++;
      sum_of_inds[nums[i]] += i;
    }
    ans[i] += sum_of_inds[nums[i]] - cnts[nums[i]] * i;
  }

  return ans;
}

int main() {
  return 0;
}
