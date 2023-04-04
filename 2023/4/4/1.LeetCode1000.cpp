/*************************************************************************
	> File Name: 1.LeetCode1000.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月04日 星期二 14时40分54秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

const int inf = 0x3f3f3f3f;

int mergeStones(vector<int>& stones, int k) {
  int n = stones.size();
  if ((n - 1) % (k - 1))
    return -1;
  int dp[31][31][31];
  int pre[n + 1];
  memset(dp, -1, sizeof(dp));
  memset(pre, 0, sizeof(pre));
  for (int i = 0; i < n; i++)
    dp[i][i][1] = 0;
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + stones[i];

  function<int(int, int, int)> dfs = [&](int l, int r, int x) -> int {
    if (dp[l][r][x] != -1)
      return dp[l][r][x];
    if (r - l + 1 < x)
      return inf;
    if (x == 1)
      return dp[l][r][x] = min(inf, dfs(l, r, k) + pre[r + 1] - pre[l]);
    int ans = inf;
    for (int i = l; i < r; i += (k - 1)) {
      ans = min(ans, dfs(l, i, 1) + dfs(i + 1, r, x - 1));
    }
    return dp[l][r][x] = ans;
  };

  return dfs(0, n - 1, 1);
}

int main() {
  return 0;
}
