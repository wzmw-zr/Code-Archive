/*************************************************************************
	> File Name: 1.LeetCode1376.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月01日 星期一 09时51分45秒
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

struct Node {
  int ind;
  int informTime;
  vector<int> next;

  Node() = default;
  Node(int ind, int informTime) : ind(ind), informTime(informTime), next(vector<int>(0)) {}
};

using PII = pair<int, int>;

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(i, informTime[i]));
  for (int i = 0; i < n; i++) {
    if (i == headID)
      continue;
    graph[manager[i]].next.push_back(i);
  }

  int ans = 0;
  queue<PII> que;
  que.push(PII(headID, 0));
  while (!que.empty()) {
    auto [id, cost] = que.front();
    que.pop();
    ans = max(ans, cost);
    for (int x : graph[id].next)
      que.push(PII(x, cost + graph[id].informTime));
  }
  return ans;
}

int main() {
  return 0;
}
