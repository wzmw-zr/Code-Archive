/*************************************************************************
	> File Name: 1.LeetCode1377.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月24日 星期三 11时10分49秒
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

double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
  vector<vector<int>> nodes(n + 1, vector<int>(0));
  for (auto && e : edges) {
    nodes[e[0]].push_back(e[1]);
    nodes[e[1]].push_back(e[0]);
  }
  double ans = 0.0;
  function<void(int, int, int, double)> dfs = [&](int ind, int fa, int step, double p) -> void {
    if (step > t)
      return;
    if (step == t && ind == target) {
      ans = p;
      return;
    }
    int cnt = nodes[ind].size();
    if (cnt == 0 && ind == target) {
      ans = p;
      return ;
    }
    if (cnt == 1) {
      if (ind != 1 && ind == target) {
        ans = p;
        return;
      }
      if (ind == 1) {
        dfs(nodes[ind][0], ind, step + 1, p);
        return ;
      } else {
        return ;
      }
    }
    for (int x : nodes[ind]) {
      if (x == fa)
        continue;
      double p_t = ind == 1 ? p / cnt : p / (cnt - 1);
      dfs(x, ind, step + 1, p_t);
    }
  };
  dfs(1, 0, 0, 1.0);
  return ans;
}

int main() {
  return 0;
}
