/*************************************************************************
	> File Name: 1.LeetCode2050.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月28日 星期五 10时07分54秒
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
  int in_deg;
  int time;
  vector<int> next;

  Node() : in_deg(0), time(0), next(vector<int>()) {}
  Node(int time) : in_deg(0), time(time), next(vector<int>()) {}
};

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(time[i]));
  for (auto && r : relations) {
    graph[r[0] - 1].next.push_back(r[1] - 1);
    graph[r[1] - 1].in_deg++;
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (!graph[i].in_deg)
      que.push(i);
  }
  int ans = 0;
  while (!que.empty()) {
    int ind = que.front();
    que.pop();
    ans = max(ans, graph[ind].time);
    for (int x : graph[ind].next) {
      graph[x].time = max(graph[x].time, graph[ind].time + time[x]);
      if (!(--graph[x].in_deg))
        que.push(x);
    }
  }
  return ans;
}

int main() {
  return 0;
}
