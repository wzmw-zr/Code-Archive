/*************************************************************************
	> File Name: 1.LeetCode1658.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月07日 星期六 09时09分58秒
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

int minOperations(vector<int>& nums, int x) {
  int n = nums.size();
  vector<long> vals;
  for (int x : nums)
    vals.push_back(x);
  for (int x : nums)
    vals.push_back(x);
  vector<long> pre(vals.begin(), vals.end());
  unordered_map<long, int> mp;
  mp[pre[0]] = 0;
  for (int i = 1; i < 2 * n; i++) {
    pre[i] += pre[i - 1];
    mp[pre[i]] = i;
  }
  int ans = INT32_MAX;
  for (int i = 0; i < 2 * n; i++) {
    if (!mp.count(pre[i] - x))
      continue;
    int l = mp[pre[i] - x], r = mp[pre[i]];
    if (l == 0 || r == n - 1 || (l < n && r >= n)) {
      if (r - l > n)
        continue;
      ans = min(ans, r - l);
    }
  }
  return ans == INT32_MAX ? -1 : ans;
}

int main() {
  return 0;
}
