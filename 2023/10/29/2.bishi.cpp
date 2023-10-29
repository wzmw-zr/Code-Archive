#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstdint>
using namespace std;

using PII = pair<int, int>;
using PIL = pair<int, long>;

struct Node {
  vector<PII> nexts;
  long dist;
  int cnt;
  int flag;

  Node() : nexts(vector<PII>(0)), dist(0), cnt(0), flag(0) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<Node> graph(n + 1);
  for (int i = 0; i < m; i++) {
    int ind;
    cin >> ind;
    graph[ind].cnt = 1;
    graph[ind].flag = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].nexts.push_back(PII(v, w));
    graph[v].nexts.push_back(PII(u, w));
  }
  function<PIL(int, int)> dfs1 = [&](int ind, int fa) -> PIL {
    for (auto && [next, w] : graph[ind].nexts) {
      if (next == fa)
        continue;
      auto [cnt, dist] = dfs1(next, ind);
      graph[ind].cnt += cnt;
      graph[ind].dist += dist + cnt;
    }
    return PIL(graph[ind].cnt, graph[ind].dist);
  };
  dfs1(1, 0);

  function<void(int, int)> dfs2 = [&](int ind, int fa) {
    for (auto && [next, w] : graph[ind].nexts) {
      if (next == fa)
        continue;
      int cnt = graph[next].cnt;
      graph[next].dist = graph[ind].dist - cnt + (m - cnt);
      dfs2(next, ind);
    }
  };
  dfs2(1, 0);
  long mmin = INT64_MAX;
  for (int i = 1; i <= n; i++)
    mmin = min(mmin, graph[i].dist);
  vector<int> inds;
  for (int i = 1; i <= n; i++) {
    if (graph[i].dist == mmin)
      inds.push_back(i);
  }
  cout << inds.size() << endl;
  for (int ind : inds)
    cout << ind << " ";
  cout << endl;
  return 0;
}
