/*************************************************************************
	> File Name: 2.LeetCode2192.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月22日 星期四 16时34分46秒
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
  set<int> ancestors;

  Node() = default;
  Node(int ind) : ind(ind), in_deg(0), next(vector<int>(0)), ancestors(set<int>()) {}
};

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
  vector<Node> nodes;
  for (int i = 0; i < n; i++)
    nodes.push_back(Node(i));
  for (auto && edge : edges) {
    int from = edge[0], to = edge[1];
    nodes[from].next.push_back(to);
    nodes[to].in_deg++;
    nodes[to].ancestors.insert(from);
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (!nodes[i].in_deg)
      que.push(i);
  }
  vector<vector<int>> ans(n);
  while (!que.empty()) {
    int ind = que.front();
    que.pop();
    ans[ind] = vector<int>(nodes[ind].ancestors.begin(), nodes[ind].ancestors.end());
    for (int x : nodes[ind].next) {
      for (int y : nodes[ind].ancestors) 
        nodes[x].ancestors.insert(y);
      if (!(--nodes[x].in_deg)) 
        que.push(x);
    }
  }
  return ans;
}

int main() {
  return 0;
}
