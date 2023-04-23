/*************************************************************************
	> File Name: 2.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月23日 星期日 16时59分24秒
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

struct Node {
  int ind;
  char color;
  vector<int> next;

  Node() = default;
  Node(int ind, char color) : ind(ind), color(color), next(vector<int>(0)) {}
};

vector<Node> graph;

struct UnionSet {
  int n;
  vector<int> fa;
  vector<int> size;

  UnionSet() = default;
  UnionSet(int n) : n(n), fa(vector<int>(n)), size(vector<int>(n, 1)) {
    for (int i = 0; i < n; i++)
      fa[i] = i;
  }

  int find(int x) {
    return fa[x] = (x == fa[x] ? x : find(fa[x]));
  }

  void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b)
      return;
    if (graph[a].color == 'R' && graph[b].color == 'R') {
      fa[a] = b;
      size[b] += size[a];
    }
  }
};

int KthConnectedComponent(int k) {
  int n = graph.size();
  UnionSet u(n);
  for (Node &node : graph) {
    for (int x : node.next)
      u.merge(node.ind, x);
  }
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++)
    mp[u.find(i)] = u.size[u.find(i)];
  if (mp.size() < k)
    return -1;
  vector<int> sizes;
  for (auto && [x, size] : mp)
    sizes.push_back(size);
  sort(sizes.begin(), sizes.end(), greater<int>());
  return sizes[k - 1];
}

int main() {
  int n, k;
  cin >> n >> k;
  string colors;
  cin >> colors;

  for (int i = 0; i < n; i++)
    graph.push_back(Node(i, colors[i]));

  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    graph[u - 1].next.push_back(v - 1);
    graph[v - 1].next.push_back(u - 1);
  }

  cout << KthConnectedComponent(k) << endl;

  return 0;
}
