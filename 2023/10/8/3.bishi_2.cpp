/*************************************************************************
	> File Name: 3.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月08日 星期日 16时01分56秒
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
#include <cstdint>
using namespace std;

struct Node {
  long val;
  vector<long> next;

  Node() = default;
};

void dfs(vector<Node> &graph, long mid, long n, long m, long ind, long &flag, long sum) {
  if (sum >= m) {
    flag = 1;
    return ;
  }
  if (flag == 1)
    return ;
  for (long next : graph[ind].next) {
    if (graph[next].val > mid)
      continue;
    dfs(graph, mid, n, m, next, flag, sum + graph[next].val);
  }
}

int main() {
  long n, m;
  cin >> n >> m;
  vector<Node> graph(n + 1);
  for (long i = 1; i <= n; i++)
    cin >> graph[i].val;
  for (long i = 1; i <= n; i++) {
    long c, t;
    cin >> c;
    for (long j = 0; j < c; j++) {
      cin >> t;
      graph[i].next.push_back(t);
    }
  }
  long ans = INT32_MAX;
  function<void(long, long, long)> dfs = [&](long ind, long sum, long mmax) {
    if (sum >= m) {
      ans = min(ans, mmax);
      return ;
    }
    for (int next : graph[ind].next)
      dfs(next, sum + graph[next].val, max(mmax, graph[next].val));
  };
  dfs(1L, graph[1].val, graph[1].val);
  cout << (ans == INT32_MAX ? -1 : ans) << endl;
  return 0;
}
