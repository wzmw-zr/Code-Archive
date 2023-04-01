/*************************************************************************
	> File Name: 5.mianshi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 10时59分57秒
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

const int RED = 1;
const int GREEN = 2;

struct Node {
  int ind;
  int color;
  vector<int> children;

  Node() = default;
  Node(int ind, int color) : ind(ind), color(color), children(vector<int>(0)) {}
};

int dfs(int ind, vector<Node> &graph) {
  if (graph[ind].children.size() == 0)
    return 1;
  int res = 0;
  if (graph[ind].color == RED) {
    for (int x : graph[ind].children)
      res += dfs(x, graph);
  } else {
    for (int x : graph[ind].children)
      res ^= dfs(x, graph);
  }
  return res;
}

int rootValue(int n, vector<int> &fa, vector<int> &color) {
  vector<Node> graph;
  for (int i = 0; i < n; i++)
    graph.push_back(Node(i, color[i]));
  for (int i = 1; i < n; i++)
    graph[fa[i]].children.push_back(i);
  return dfs(0, graph);
}

int main() {
  int n;
  cin >> n;
  vector<int> fa(n, 0);
  vector<int> color(n);
  for (int i = 1; i < n; i++) {
    cin >> fa[i];
    fa[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> color[i];
  }
  cout << rootValue(n, fa, color) << endl;
  return 0;
}
