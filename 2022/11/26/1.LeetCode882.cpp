/*************************************************************************
	> File Name: 1.LeetCode882.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月26日 星期六 09时44分15秒
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

struct Edge {
  int id;
  int from;
  int to;
  int cnt;

  Edge() = default;
  Edge(int id, int from, int to, int cnt) : id(id), from(from), to(to), cnt(cnt) {}
};

struct Node {
  int ind;
  int dis;

  Node() = default;
  Node(int ind, int dis) : ind(ind), dis(dis) {}

  bool operator<(const struct Node &that) const {
    return this->dis < that.dis;
  };

  bool operator>(const struct Node &that) const {
    return this->dis > that.dis;
  };
};

int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
  vector<vector<Edge>> nodes(n, vector<Edge>(0));
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0], v = edges[i][1], cnt = edges[i][2];
    nodes[u].push_back(Edge(i, u, v, cnt));
    nodes[v].push_back(Edge(i, v, u, cnt));
  }
  vector<int> check(n, 0);
  priority_queue<Node, vector<Node>, greater<Node>> que;
  que.push(Node(0, 0));
  vector<int> cnts(edges.size(), 0);
  while (!que.empty()) {
    Node temp = que.top();
    que.pop();
    if (check[temp.ind])
      continue;
    if (temp.dis > maxMoves)
      continue;
    check[temp.ind] = 1;
    for (auto && edge : nodes[temp.ind]) {
      cnts[edge.id] = min(edges[edge.id][2], cnts[edge.id] + maxMoves - temp.dis);
      que.push(Node(edge.to, temp.dis + edge.cnt + 1));
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += check[i];
  for (int i = 0; i < edges.size(); i++)
    ans += cnts[i];
  return ans;
}

int main() {
  return 0;
}
