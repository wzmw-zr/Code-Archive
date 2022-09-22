/*************************************************************************
	> File Name: 3.LeetCode1786.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月22日 星期四 18时52分00秒
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

using PII = pair<int, int>;

struct Node {
  int ind;
  vector<PII> next;

  Node() = default;
  Node(int ind) : ind(ind), next(vector<PII>(0)) {}
};

struct Point {
  int ind;
  int dis;

  Point() = default;
  Point(int ind, int dis) : ind(ind), dis(dis) {}

  bool operator<(const struct Point &that) const {
    return this->dis > that.dis;
  }
};

const long MOD = 1e9 + 7;

int countRestrictedPaths(int n, vector<vector<int>>& edges) {
  vector<Node> nodes;
  nodes.push_back(Node(0));
  for (int i = 1; i <= n; i++) 
    nodes.push_back(Node(i));
  for (auto && edge : edges) {
    int u = edge[0], v = edge[1], w = edge[2];
    nodes[u].next.push_back(PII(v, w));
    nodes[v].next.push_back(PII(u, w));
  }
  vector<int> check(n + 1, 0);
  vector<int> dis(n + 1, 0);
  priority_queue<Point> que;
  que.push(Point(n, 0));
  while (!que.empty()) {
    Point t = que.top();
    que.pop();
    if (check[t.ind])
      continue;
    check[t.ind] = 1;
    dis[t.ind] = t.dis;
    for (auto [next_ind, dist] : nodes[t.ind].next) {
      if (check[next_ind])
        continue;
      que.push(Point(next_ind, t.dis + dist));
    }
  }

  function<bool(int, int)> cmp = [&](int x, int y) -> bool {
    return dis[x] < dis[y];
  };
  check = vector<int>(n + 1, 0);
  priority_queue<int, vector<int>, decltype(cmp)> que_2(cmp);
  vector<long> cnts(n + 1, 0);
  cnts[1] = 1;
  que_2.push(1);
  check[1] = 1;
  while (!que_2.empty()) {
    int ind = que_2.top();
    long cnt = cnts[ind];
    que_2.pop();
    if (ind == n)
      return cnt;
    for (auto [next_ind, dist] : nodes[ind].next) {
      if (dis[next_ind] >= dis[ind])
        continue;
      if (!check[next_ind]) {
        check[next_ind] = 1;
        que_2.push(next_ind);
      }
      cnts[next_ind] = (cnts[next_ind] + cnt) % MOD;
    }
  }
  return -1;
}

int main() {
  return 0;
}
