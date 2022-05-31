/*************************************************************************
	> File Name: 2.LeetCode2127.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月31日 星期二 21时42分17秒
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

// WA
struct Node {
  int ind;
  int next;
  int in_deg;
  int height;
  int visited;

  Node() = default;
  Node(int ind) : ind(ind), next(0), in_deg(0), height(1), visited(0) {}
};

int dfs(vector<Node> &nodes, int ind) {
  if (nodes[ind].visited) return 0;
  nodes[ind].visited = 1;
  return dfs(nodes, nodes[ind].next) + 1;
}

int maximumInvitations(vector<int>& favorite) {
  int n = favorite.size();
  vector<Node> nodes;
  for (int i = 0; i < n; i++) nodes.push_back(Node(i));
  for (int i = 0; i < n; i++) {
    nodes[i].next = favorite[i];
    nodes[favorite[i]].in_deg++;
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (nodes[i].in_deg) continue;
    que.push(i);
  }
  while (!que.empty()) {
    int ind = que.front();
    que.pop();
    int h = nodes[nodes[ind].next].height;
    nodes[nodes[ind].next].height = max(h, nodes[ind].height + 1);
    if (!(--nodes[nodes[ind].next].in_deg)) que.push(nodes[ind].next);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!nodes[i].in_deg || nodes[i].visited) continue;
    int len = dfs(nodes, i);
    if (len >= 3) ans = max(ans, len);
    else ans = max({ans, nodes[i].height + 1, nodes[nodes[i].next].height + 1});
  }
  return ans;
}

int main() {
  return 0;
}
