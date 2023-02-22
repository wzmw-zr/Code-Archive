/*************************************************************************
	> File Name: 1.LeetCode1140.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月22日 星期三 09时32分03秒
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

using PII = pair<int, int>;

int stoneGameII(vector<int>& piles) {
  int n = piles.size();
  vector<int> pre(n + 1, 0), suf(n + 1, 0);
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + piles[i];
  for (int i = n - 1; i >= 0; i--)
    suf[i] = suf[i + 1] + piles[i];
  map<PII, int> mp;
  function<int(int, int)> dfs = [&](int ind, int m) -> int {
    if (ind == n)
      return 0;
    PII state(ind, m);
    if (mp.count(state))
      return mp[state];
    int ans = 0;
    for (int x = 1; (ind + x <= n) && (x <= 2 * m); x++)
      ans = max(ans, pre[ind + x] - pre[ind] + suf[ind + x] - dfs(ind + x, max(x, m)));
    return mp[state] = ans;
  };
  return dfs(0, 1);
}

int main() {
  return 0;
}
