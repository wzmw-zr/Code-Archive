/*************************************************************************
	> File Name: 5.LeetCode6032.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月13日 星期日 16时33分57秒
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

using PLL = pair<long long, long long>;

vector<long long> dijkstra(vector<vector<PLL>> &graph, int start) {
  int n = graph.size();
  vector<long long> ans(n, INT64_MAX);
  priority_queue<PLL, vector<PLL>, greater<PLL>> que;
  que.push(PLL(0, start));
  while (!que.empty()) {
    PLL temp = que.top();
    que.pop();
    if (ans[temp.second] <= temp.first) continue;
    ans[temp.second] = temp.first;
    for (auto e : graph[temp.second]) que.push(PLL(temp.first + e.second, e.first));
  }
  return ans;
}

long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
  vector<vector<PLL>> graph(n, vector<PLL>(0));
  vector<vector<PLL>> b_graph(n, vector<PLL>(0));
  for (auto e : edges) {
    graph[e[0]].push_back(PLL(e[1], e[2]));
    b_graph[e[1]].push_back(PLL(e[0], e[2]));
  }
  vector<long long> dis1 = dijkstra(graph, src1);
  vector<long long> dis2 = dijkstra(graph, src2);
  vector<long long> dis3 = dijkstra(b_graph, dest);
  long long ans = INT64_MAX;
  for (int i = 0; i < n; i++) {
    if (dis1[i] == INT64_MAX || dis2[i] == INT64_MAX || dis3[i] == INT64_MAX) continue;
    ans = min(ans, dis1[i] + dis2[i] + dis3[i]);
  }
  return ans == INT64_MAX ? -1 : ans;
}

int main() {
  return 0;
}
