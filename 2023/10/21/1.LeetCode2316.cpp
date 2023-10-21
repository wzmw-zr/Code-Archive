/*************************************************************************
	> File Name: 1.LeetCode2316.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月21日 星期六 11时11分24秒
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

long long countPairs(int n, vector<vector<int>>& edges) {
  vector<vector<int>> graph(n, vector<int>(0));
  for (auto && e : edges) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  vector<int> check(n, 0);
  function<int(int)> dfs = [&](int ind) -> int {
    if (check[ind])
      return 0;
    check[ind] = 1;
    int sum = 1;
    for (int next : graph[ind])
      sum += dfs(next);
    return sum;
  };
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (check[i])
      continue;
    int cnt = dfs(i);
    sum += 1L * cnt * (n - cnt);
  }
  sum /= 2L;
  return sum;
}

int main() {
  return 0;
}
