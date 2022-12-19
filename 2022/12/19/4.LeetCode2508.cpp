/*************************************************************************
	> File Name: 4.LeetCode2508.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月19日 星期一 11时17分57秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool isPossible(int n, vector<vector<int>>& edges) {
  vector<unordered_set<int>> graph(n + 1, unordered_set<int>());
  for (auto && edge : edges) {
    graph[edge[0]].insert(edge[1]);
    graph[edge[1]].insert(edge[0]);
  }
  vector<int> odd_deg_nodes;
  for (int i = 1; i <= n; i++) {
    if (graph[i].size() & 1)
      odd_deg_nodes.push_back(i);
  }
  if (odd_deg_nodes.size() > 4)
    return false;
  if (odd_deg_nodes.size() & 1)
    return false;
  if (odd_deg_nodes.size() == 4) {
    for (int i = 1; i < 4; i++) {
      set<int> st({1, 2, 3});
      int u1 = odd_deg_nodes[0];
      int v1 = odd_deg_nodes[i];
      st.erase(i);
      int u2 = odd_deg_nodes[*st.begin()];
      int v2 = odd_deg_nodes[*st.rbegin()];
      if (graph[u1].count(v1) || graph[u2].count(v2))
        continue;
      return true;
    }
    return false;
  }
  if (odd_deg_nodes.size() == 2) {
    int u1 = odd_deg_nodes[0];
    int v1 = odd_deg_nodes[1];
    if (!graph[u1].count(v1))
      return true;
    unordered_set<int> st;
    for (int i = 1; i <= n; i++)
      st.insert(i);
    st.erase(u1);
    st.erase(v1);
    for (int x : graph[u1])
      st.erase(x);
    for (int x : graph[v1])
      st.erase(x);
    if (st.size())
      return true;
    else
      return false;
  }
  return true;
}

int main() {
  return 0;
}
