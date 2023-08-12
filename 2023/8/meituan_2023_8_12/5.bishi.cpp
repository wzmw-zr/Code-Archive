/*************************************************************************
	> File Name: 5.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月12日 星期六 10时33分49秒
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
#include <cmath>
using namespace std;

struct Node {
  long val;
  vector<int> next;

  Node() : val(0), next(vector<int>(0)) {}
};

int check(long x) {
  long y = sqrt(x * 1.0);
  return y * y == x;
}

int main() {
  int n;
  cin >> n;
  vector<Node> graph(n);
  for (int i = 0; i < n; i++)
    cin >> graph[i].val;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u - 1].next.push_back(v - 1);
    graph[v - 1].next.push_back(u - 1);
  }
  function<int(int, int, int)> dfs = [&](int ind, int fa, int red) -> int {
    int ans = 0;
    if (red) {
      for (int x : graph[ind].next) {
        if (x == fa)
          continue;
        ans += dfs(x, ind, 0);
      }
    } else {
      int n = graph[ind].next.size();
      vector<int> no_color(n, 0);
      for (int i = 0; i < n; i++) {
        int x = graph[ind].next[i];
        if (x == fa)
          continue;
        no_color[i] = dfs(x, ind, 0);
      }
      int sum = 0;
      for (int x : no_color)
        sum += x;
      ans = sum;
      for (int i = 0; i < n; i++) {
        int x = graph[ind].next[i];
        if (x == fa)
          continue;
        if (check(graph[ind].val * graph[x].val)) {
          ans = max(ans, sum - no_color[i] + dfs(x, ind, 1) + 2);
        }
      }
    }
    return ans;
  };
  cout << dfs(0, -1, 0) << endl;
  return 0;
}
