/*************************************************************************
	> File Name: 2.LeetCode2646.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月22日 星期六 14时33分18秒
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

  int height;
  int size;
  int pa;
  int heavy_child;

  int top;
  int dfs_id;

  vector<int> next;

  Node() = default;
  Node(int ind, int price) : ind(ind), price(price), cnt(0), height(0), size(1), pa(-1), heavy_child(-1), top(-1), dfs_id(-1), next(vector<int>(0)) {}
};

int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(i, price[i]));
  for (auto && e : edges) {
    if (e[0] != e[1]) {
      graph[e[0]].next.push_back(e[1]);
      graph[e[1]].next.push_back(e[0]);
    } else {
      graph[e[0]].next.push_back(e[1]);
    }
  }

  function<int(int, int, int)> dfs1 = [&](int sn, int fa, int height) -> int {
    graph[sn].pa = fa;
    graph[sn].height = height;

    int mmax = -1;
    for (int fn : graph[sn].next) {
      if (fn == fa)
        continue;
      int t = dfs1(fn, sn, height + 1);
      graph[sn].size += t;
      if (t > mmax)
        graph[sn].heavy_child = fn;
    }

    return graph[sn].size;
  };

  dfs1(0, -1, 0);

  function<void(int, int, int, int &)> dfs2 = [&](int sn, int fa, int top, int &dfs_id) -> void {
    graph[sn].top = top;
    graph[sn].dfs_id = dfs_id++;
    if (graph[sn].heavy_child != -1)
      dfs2(graph[sn].heavy_child, sn, top, dfs_id);
    for (int fn : graph[sn].next) {
      if (fn == fa || fn == graph[sn].heavy_child)
        continue;
      dfs2(fn, sn, fn, dfs_id);
    }
  };

  int dfs_id = 0;
  dfs2(0, -1, 0, dfs_id);

  function<int(int, int)> LCA = [&](int x, int y) -> int {
    while (graph[x].top != graph[y].top) {
      if (graph[graph[x].top].height > graph[graph[y].top].height)
        x = graph[graph[x].top].pa;
      else
        y = graph[graph[y].top].pa;
    }
    return graph[x].height < graph[y].height ? x : y;
  };

  for (auto && trip : trips) {
    if (trip[0] == trip[1]) {
      graph[trip[0]].cnt++;
      int pa = graph[trip[0]].pa;
      if (pa >= 0)
        graph[pa].cnt--;
    } else {
      int lca = LCA(trip[0], trip[1]);
      int pa = graph[lca].pa;
      graph[trip[0]].cnt++;
      graph[trip[1]].cnt++;
      graph[lca].cnt--;
      if (pa >= 0)
        graph[pa].cnt--;
    }
  }


  function<int(int, int)> dfs3 = [&](int sn, int fa) -> int {
    for (int fn : graph[sn].next) {
      if (fn == fa)
        continue;
      graph[sn].cnt += dfs3(fn, sn);
    }
    return graph[sn].cnt;
  };

  dfs3(0, -1);

  vector<vector<int>> dp(n, vector<int>(2, -1));
  function<int(int, int, int)> dfs4 = [&](int sn, int fa, int change) -> int {
    if (dp[sn][change] != -1)
      return dp[sn][change];
    int ans = change ? graph[sn].price / 2 * graph[sn].cnt : 0;
    for (int fn : graph[sn].next) {
      if (fn == fa)
        continue;
      if (change) {
        ans += dfs4(fn, sn, 0);
      } else {
        ans += max(dfs4(fn, sn, 0), dfs4(fn, sn, 1));
      }
    }
    return dp[sn][change] = ans;
  };

  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += graph[i].price * graph[i].cnt;
  
  int mmax = max(dfs4(0, -1, 0), dfs4(0, -1, 1));
  return sum - mmax;
}

int main() {
  return 0;
}
