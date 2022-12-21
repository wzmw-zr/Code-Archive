/*************************************************************************
	> File Name: 1.LeetCode1799.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月22日 星期四 00时32分12秒
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
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int maxScore(vector<int>& nums) {
  int m = nums.size();
  int state = (1 << m) - 1;
  unordered_map<int, int> mp;
  function<int(int)> dfs = [&](int stat) -> int {
    if (!stat)
      return 0;
    if (mp.count(stat))
      return mp[stat];
    int ans = 0;
    int step = m / 2 - __builtin_popcount(stat) / 2 + 1;
    for (int i = 0; i < m; i++) {
      if (!(stat & (1 << i)))
        continue;
      stat ^= 1 << i;
      for (int j = i + 1; j < m; j++) {
        if (!(stat & (1 << j)))
          continue;
        stat ^= 1 << j;
        ans = max(ans, step * gcd(nums[i], nums[j]) + dfs(stat));
        stat ^= 1 << j;
      }
      stat ^= 1 << i;
    }
    return mp[stat] = ans;
  };
  return dfs(state);
}

int main() {
  return 0;
}
