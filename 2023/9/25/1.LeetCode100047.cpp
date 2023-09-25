/*************************************************************************
	> File Name: 1.LeetCode100047.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月25日 星期一 10时07分10秒
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

using PLL = pair<long, long>;

long long countPaths(int n, vector<vector<int>>& edges) {
  vector<vector<int>> graph(n + 1);
  for (auto && e : edges) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  vector<int> is_prime(n + 1, 1);
  is_prime[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (!is_prime[i])
      continue;
    for (int j = 2; i * j <= n; j++)
      is_prime[i * j] = 0;
  }

  long ans = 0;
  function<PLL(int, int)> dfs = [&](int ind, int fa) -> PLL {
    long zero = is_prime[ind] ? 0 : 1;
    long one = is_prime[ind] ? 1 : 0;
    for (int next : graph[ind]) {
      if (next == fa)
        continue;
      auto [x, y] = dfs(next, ind);
      ans += (x * one) + (y * zero);
      if (is_prime[ind])
        one += x;
      else
        zero += x, one += y;
    }
    return PLL(zero, one);
  };

  dfs(1, 0);
  return ans;
}

int main() {
  return 0;
}
