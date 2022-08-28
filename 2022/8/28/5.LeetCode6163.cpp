/*************************************************************************
	> File Name: 5.LeetCode6163.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月28日 星期日 10时59分20秒
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
  int in_deg;
  vector<int> next;

  Node() = default;
  Node(int ind) : ind(ind), in_deg(0), next(vector<int>(0)) {}
};

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
  unordered_map<int, Node> row_graph, col_graph;
  for (int i = 1; i <= k; i++) {
    row_graph[i] = Node(i);
    col_graph[i] = Node(i);
  }
  for (auto && x : rowConditions) {
    row_graph[x[0]].next.push_back(x[1]);
    row_graph[x[1]].in_deg++;
  }
  for (auto && x : colConditions) {
    col_graph[x[0]].next.push_back(x[1]);
    col_graph[x[1]].in_deg++;
  }
  unordered_map<int, int> mp1;
  queue<int> que;
  int ind = 0;
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    if (row_graph[i].in_deg)
      continue;
    que.push(i);
  }
  while (!que.empty()) {
    int t = que.front();
    que.pop();
    cnt++;
    mp1[t] = ind++;
    for (int x : row_graph[t].next) {
      if (!(--row_graph[x].in_deg))
        que.push(x);
    }
  }
  if (cnt != k) return {};

  unordered_map<int, int> mp2;
  ind = 0;
  cnt = 0;
  for (int i = 1; i <= k; i++) {
    if (col_graph[i].in_deg)
      continue;
    que.push(i);
  }
  while (!que.empty()) {
    int t = que.front();
    que.pop();
    cnt++;
    mp2[t] = ind++;
    for (int x : col_graph[t].next) {
      if (!(--col_graph[x].in_deg))
        que.push(x);
    }
  }
  if (cnt != k) return {};
  vector<vector<int>> ans(k, vector<int>(k, 0));
  for (int i = 1; i <= k; i++)
    ans[mp1[i]][mp2[i]] = i;
  return ans;
}

int main() {
  return 0;
}
