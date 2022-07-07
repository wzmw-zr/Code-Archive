/*************************************************************************
	> File Name: 2.LeetCode2247.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月07日 星期四 21时19分28秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PII = pair<int, int>;

int maximumCost(int n, vector<vector<int>>& highways, int k) {
  if (k >= n) return -1;
  vector<vector<int>> graph(n, vector<int>(0));
  int price[n][n];
  for (auto && x : highways) {
    price[x[0]][x[1]] = x[2];
    price[x[1]][x[0]] = x[2];
    graph[x[0]].push_back(x[1]);
    graph[x[1]].push_back(x[0]);
  }
  int dp[(1 << n)][n];
  int check[(1 << n)][n];
  memset(dp, -1, sizeof(dp));
  memset(dp[0], 0, sizeof(dp[0]));
  memset(check, 0, sizeof(check));
  queue<PII> que;
  for (int i = 0; i < n; i++) {
    que.push(PII((1 << i), i));
    dp[1 << i][i] = 0;
    check[1 << i][i] = 1;
  }
  int ans = -1;
  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      auto [state, city] = que.front();
      que.pop();
      if (__builtin_popcount(state) == k + 1) ans = max(ans, dp[state][city]);
      for (int next_city : graph[city]) {
        if (state & (1 << next_city)) continue;
        int next_state = state | (1 << next_city);
        if (dp[state][city] + price[city][next_city] > dp[next_state][next_city]) {
          if (!check[next_state][next_city])
            que.push(PII(next_state, next_city));
          dp[next_state][next_city] = dp[state][city] + price[city][next_city];
          check[next_state][next_city] = 1;
        }
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
