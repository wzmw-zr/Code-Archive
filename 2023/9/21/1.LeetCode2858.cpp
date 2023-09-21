/*************************************************************************
	> File Name: 1.LeetCode2858.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月21日 星期四 14时24分16秒
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

using PII = pair<int, int>;

vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
  vector<vector<PII>> graph(n);
  for (auto && e : edges) {
    graph[e[0]].push_back(PII(e[1], 0));
    graph[e[1]].push_back(PII(e[0], 1));
  }
  vector<int> dp(n);
  function<int(int, int)> dfs1 = [&](int ind, int fa) -> int {
    int ans = 0;
    for (auto && [next, rev] : graph[ind]) {
      if (next == fa)
        continue;
      ans += rev + dfs1(next, ind);
    }
    return dp[ind] = ans;
  };
  dfs1(0, -1);

  function<void(int, int)> dfs2 = [&](int ind, int fa) {
    for (auto && [next, rev] : graph[ind]) {
      if (next == fa)
        continue;
      dp[next] = dp[ind] + (rev == 0 ? 1 : -1);
      dfs2(next, ind);
    }
  };
  dfs2(0, -1);

  return dp;
}

int main() {
  return 0;
}
