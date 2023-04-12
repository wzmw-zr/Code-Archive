/*************************************************************************
	> File Name: 1.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月12日 星期三 11时18分35秒
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

const char RED = 'R';
const char BLUE = 'B';

int total_red = 0;
int total_blue = 0;
int ans = 0;

struct Node {
  int ind;
  char color;
  vector<int> next;

  Node() = default;
  Node(int ind, char color) : ind(ind), color(color), next(vector<int>(0)) {}
};

using PII = pair<int, int>;

PII dfs(vector<Node> &graph, int ind, int fa) {
  int num_red = graph[ind].color == RED ? 1 : 0;
  int num_blue = graph[ind].color == BLUE ? 1 : 0;

  for (int x : graph[ind].next) {
    if (x == fa)
      continue;
    auto [cnt_red, cnt_blue] = dfs(graph, x, ind);
    if (cnt_red > cnt_blue && (total_red - cnt_red) > (total_blue - cnt_blue))
      ans++;
    num_red += cnt_red;
    num_blue += cnt_blue;
  }

  return PII(num_red, num_blue);
}

int main() {
  int n;
  cin >> n;
  string colors(n, ' ');
  for (int i = 0; i < n; i++) {
    cin >> colors[i];
    if (colors[i] == RED)
      total_red++;
    else
      total_blue++;
  }
  vector<Node> graph;
  for (int i = 0; i < n; i++) 
    graph.push_back(Node(i, colors[i]));
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    graph[a - 1].next.push_back(b - 1);
    graph[b - 1].next.push_back(a - 1);
  }
  dfs(graph, 0, -1);
  cout << ans << endl;
  return 0;
}
