/*************************************************************************
	> File Name: 1.LeetCode1590.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月10日 星期五 09时53分16秒
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

int minSubarray(vector<int>& nums, int p) {
  int n = nums.size();
  vector<int> pre(n + 1, 0);
  for (int i = 0; i < n; i++)
    pre[i + 1] = (pre[i] + nums[i]) % p;
  int ans = INT32_MAX;
  unordered_map<int, int> mp;
  mp[0] = 0;
  for (int i = 1; i <= n; i++) {
    mp[pre[i]] = i;
    int val = (pre[i] - pre[n] + p) % p;
    if (mp.count(val))
      ans = min(ans, i - mp[val]);
  }
  return (ans == INT32_MAX || ans == n) ? -1 : ans;
}

int main() {
  return 0;
}
