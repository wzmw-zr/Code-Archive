/*************************************************************************
	> File Name: 1.LeetCode2646.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月21日 星期五 14时40分52秒
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

struct Node {
  int ind;
  int price;
  int cnt;
  vector<int> next;

  Node() = default;
  Node(int ind, int price) : ind(ind), price(price), cnt(0), next(vector<int>(0)) {}
};

int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(i, price[i]));
  for (auto && e : edges) {
    graph[e[0]].next.push_back(e[1]);
    graph[e[1]].next.push_back(e[0]);
  }

  function<int(int, int, int)> dfs1 = [&](int ind, int target, int fa) -> int {
    if (ind == target) {
      graph[ind].cnt++;
      return 1;
    }
    for (int x : graph[ind].next) {
      if (x == fa)
        continue;
      int t = dfs1(x, target, ind);
      if (t == 1) {
        graph[ind].cnt++;
        return t;
      }
    }
    return 0;
  };

  for (auto && trip : trips)
    dfs1(trip[0], trip[1], -1);

  vector<vector<int>> dp(n, vector<int>(2, -1));
  function<int(int, int, int)> dfs2 = [&](int ind, int change, int fa) -> int {
    if (dp[ind][change] != -1)
      return dp[ind][change];
    int ans = 0;
    if (change)
      ans = graph[ind].price / 2 * graph[ind].cnt;
    for (int x : graph[ind].next) {
      if (x == fa)
        continue;
      if (change) {
        ans += dfs2(x, 0, ind);
      } else {
        ans += max(dfs2(x, 0, ind), dfs2(x, 1, ind));
      }
    }
    return dp[ind][change] = ans;
  };

  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += graph[i].cnt * graph[i].price;
  return sum - max(dfs2(0, 0, -1), dfs2(0, 1, -1));
}

int main() {
  return 0;
}
