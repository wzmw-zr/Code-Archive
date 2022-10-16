/*************************************************************************
	> File Name: 6.LeetCode886.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月16日 星期日 11时10分01秒
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

struct UnionSet {
  vector<int> fa;

  UnionSet(int n) : fa(vector<int>(n, 0)) {
    for (int i = 0; i < n; i++)
      fa[i] = i;
  }

  int find(int x) {
    return fa[x] = (x == fa[x] ? x : find(fa[x]));
  }

  void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b)
      return ;
    fa[a] = b;
  }

  bool is_connected(int x, int y) {
    return find(x) == find(y);
  }
};

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
  UnionSet u(n + 1);
  vector<vector<int>> graph(n + 1, vector<int>(0));
  for (auto && d : dislikes) {
    graph[d[0]].push_back(d[1]);
    graph[d[1]].push_back(d[0]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < graph[i].size(); j++) 
      u.merge(graph[i][0], graph[i][j]);
    if (graph[i].size() && u.is_connected(i, graph[i][0]))
      return false;
  }
  return true;
}

int main() {
  return 0;
}
