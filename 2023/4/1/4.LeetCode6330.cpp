/*************************************************************************
	> File Name: 4.LeetCode6330.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 22时56分17秒
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
using namespace std;

// stackoverflow
int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
  int ind;
  unordered_set<int> out;

  Node() = default;
};

void dfs(vector<Node> &graph, unordered_set<int> &st, int step, int ind, int &ans, int start, int fa) {
  if (step > ans)
    return ;
  if (ind == start && step) {
    ans = min(ans, step);
    return ;
  }
  st.insert(ind);
  for (int x : graph[ind].out) {
    if (x == fa)
      continue;
    dfs(graph, st, step + 1, x, ans, start, ind);
  }
  st.erase(ind);
}

int findShortestCycle(int n, vector<vector<int>>& edges) {
  vector<Node> graph(n);
  for (int i = 0; i < n; i++)
    graph[i].ind = i;
  for (auto && e : edges) {
    graph[e[0]].out.insert(e[1]);
    graph[e[1]].out.insert(e[0]);
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (graph[i].out.size() <= 1)
      que.push(i);
  }

  while (!que.empty()) {
    int t = que.front();
    que.pop();
    for (int x : graph[t].out) {
      graph[x].out.erase(t);
      if (graph[x].out.size() <= 1)
        que.push(x);
    }
    graph[t].out = unordered_set<int>();
  }

  vector<int> nodes;
  for (int i = 0; i < n; i++) {
    if (graph[i].out.size())
      nodes.push_back(i);
  }

  int ans = INT32_MAX;
  for (int x : nodes) {
    unordered_set<int> st;
    int min_circle = INT32_MAX;
    dfs(graph, st, 0, x, min_circle, x, x);
    ans = min(ans, min_circle);
  }
  return ans == INT32_MAX ? -1 : ans;
}

int main() {
  return 0;
}
