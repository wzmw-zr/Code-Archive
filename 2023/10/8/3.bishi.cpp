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

long check(vector<Node> &graph, long mid, long n, long m) {
  long flag = 0;
  dfs(graph, mid, n, m, 1, flag, graph[1].val);
  return flag;
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
  long l = graph[1].val - 1, r = 0, mmax = 0;
  for (long i = 1; i <= n; i++)
    mmax = max(mmax, graph[i].val);
  r = mmax + 1;
  while (l < r) {
    long mid = (l + r) / 2;
    if (check(graph, mid, n, m))
      r = mid;
    else
      l = mid + 1;
  }
  if (l == graph[1].val - 1 || l == mmax + 1) {
    cout << -1 << endl;
  } else {
    cout << l << endl;
  }
  return 0;
}
