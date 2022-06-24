/*************************************************************************
	> File Name: 1.LeetCode805.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月24日 星期五 11时08分43秒
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

// TLE
unordered_map<int, bool> mp;

bool dfs(int state, int sum, int tot, int n, vector<int> &nums) {
  if (__builtin_popcount(state) > n / 2) return mp[state] = false;
  if (mp.count(state)) return mp[state];
  int x = __builtin_popcount(state);
  if (x && (sum * n == tot * x)) return mp[state] = true;
  for (int i = 0; i < n; i++) {
    if (state & (1 << i)) continue;
    int t_state = state | (1 << i);
    mp[t_state] = dfs(t_state, sum + nums[i], tot, n, nums);
    if (mp[t_state]) return mp[state] = true;
  }
  return mp[state] = false;
}

bool splitArraySameAverage(vector<int>& nums) {
  int n = nums.size();
  int tot = 0;
  for (int x : nums) tot += x;
  return dfs(0, 0, tot, n, nums);
}

int main() {
  return 0;
}
