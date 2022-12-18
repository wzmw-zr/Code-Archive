/*************************************************************************
	> File Name: 1.LeetCode1971.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月19日 星期一 00时39分33秒
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
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
  vector<vector<int>> graph(n, vector<int>(0));
  for (auto && edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  vector<int> check(n, 0);
  function<bool(int s, int t)> dfs = [&](int s, int t) -> bool {
    if (s == t)
      return true;
    if (check[s])
      return false;
    check[s] = 1;
    for (int x : graph[s]) {
      if (dfs(x, t))
        return true;
    }
    return false;
  };
  return dfs(source, destination);
}

int main() {
  return 0;
}
