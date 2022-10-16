/*************************************************************************
	> File Name: 5.LeetCode886.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月16日 星期日 10时41分20秒
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

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
  vector<vector<int>> graph(n + 1, vector<int>(0));
  for (auto && d : dislikes) {
    graph[d[0]].push_back(d[1]);
    graph[d[1]].push_back(d[0]);
  }
  vector<int> color(n + 1, -1);
  vector<int> check(n + 1, 0);
  function<bool(int, int)> dfs = [&](int ind, int fa) -> bool {
    check[ind] = 1;
    for (int next_ind : graph[ind]) {
      if (next_ind == fa)
        continue;
      if (check[next_ind]) {
        if (color[ind] == color[next_ind])
          return false;
      } else {
        color[next_ind] = !color[ind];
        if (!dfs(next_ind, ind))
          return false;
      }
    }
    return true;
  };
  for (int i = 1; i <= n; i++) {
    if (check[i])
      continue;
    color[i] = 0;
    if (!dfs(i, -1))
      return false;
  }
  return true;
}

int main() {
  return 0;
}
