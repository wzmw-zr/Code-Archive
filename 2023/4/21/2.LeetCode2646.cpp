/*************************************************************************
	> File Name: 2.LeetCode2646.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月21日 星期五 21时06分48秒
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
#include <numeric>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct UnionSet {
  vector<int> fa;

  UnionSet() = default;
  UnionSet(int n) : fa(vector<int>(n)) {
    iota(fa.begin(), fa.end(), 0);
  }

  int find(int x) {
    return fa[x] = (x == fa[x] ? x : find(fa[x]));
  }

  void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b)
      return;
    fa[a] = b;
  }
};

struct Node {
  int ind;
  int price;
  bool visited;
  int cnt;
  int pa;
  vector<int> next;

  Node() = default;
  Node(int ind, int price) : ind(ind), price(price), visited(false), cnt(0), pa(-1), next(vector<int>(0)) {}
};

int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
  UnionSet u(n);
  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(i, price[i]));
  for (auto && e : edges) {
    graph[e[0]].next.push_back(e[1]);
    graph[e[1]].next.push_back(e[0]);
  }

  vector<vector<int>> targets(n, vector<int>(0));
  for (auto && trip : trips) {
    if (trip[0] != trip[1]) {
      targets[trip[0]].push_back(trip[1]);
      targets[trip[1]].push_back(trip[0]);
    } else {
      targets[trip[0]].push_back(trip[1]);
    }
  }


  function<void(int, int)> tarjan = [&](int sn, int fa) -> void {
    graph[sn].pa = fa;

    for (int fn : graph[sn].next) {
      if (fn == fa)
        continue;
      tarjan(fn, sn);
      u.merge(fn, sn);
    }

    graph[sn].visited = true;
    for (int x : targets[sn]) {
      if (graph[x].visited) {
        if (x == sn) {
          graph[sn].cnt++;
          if (fa >= 0)
            graph[fa].cnt--;
        } else {
          int a = u.find(x);
          int pa = graph[a].pa;
          graph[sn].cnt++;
          graph[x].cnt++;
          graph[a].cnt--;
          if (pa >= 0)
            graph[pa].cnt--;
        }
      }
    }
  };

  tarjan(0, -1);

  function<int(int, int)> dfs1 = [&](int sn, int fa) -> int {
    for (int x : graph[sn].next) {
      if (x == fa)
        continue;
      graph[sn].cnt += dfs1(x, sn);
    }
    return graph[sn].cnt;
  };

  dfs1(0, -1);

  vector<vector<int>> dp(n, vector<int>(2, -1));
  function<int(int, int, int)> dfs2 = [&](int sn, int fa, int change) -> int {
    if (dp[sn][change] != -1)
      return dp[sn][change];
    int ans = change ? graph[sn].price / 2 * graph[sn].cnt : 0;
    for (int x : graph[sn].next) {
      if (x == fa)
        continue;
      if (change) {
        ans += dfs2(x, sn, 0);
      } else {
        ans += max(dfs2(x, sn, 0), dfs2(x, sn, 1));
      }
    }
    return dp[sn][change] = ans;
  };

  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += graph[i].cnt * graph[i].price;
  int mmax = max(dfs2(0, -1, 0), dfs2(0, -1, 1));
  return sum - mmax;
}

int main() {
  return 0;
}
