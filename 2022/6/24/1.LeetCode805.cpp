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

// WA
using PII = pair<int, int>;

map<PII, bool> mp;

bool dfs(int state, int ind, int sum, int tot, int n, vector<int> &nums) {
  PII embd(state, ind);
  if (mp.count(embd)) return mp[embd];
  int x = __builtin_popcount(state);
  if (x && (sum * n == tot * x)) return mp[embd] = true;
  if (ind == n) return mp[embd] = false;
  if (x > n / 2) return mp[embd] = false;

  bool res1 = dfs(state, ind + 1, sum, tot, n, nums);
  if (res1) return mp[embd] = true;

  bool res2 = dfs(state | (1 << ind), ind + 1, sum + nums[ind], tot, n, nums);
  if (res2) return mp[embd] = true;

  return mp[embd] = false;
}

bool splitArraySameAverage(vector<int>& nums) {
  int n = nums.size();
  int tot = 0;
  for (int x : nums) tot += x;
  return dfs(0, 0, 0, tot, n, nums);
}

int main() {
  return 0;
}
