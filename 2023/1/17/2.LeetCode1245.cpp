/*************************************************************************
	> File Name: 2.LeetCode1245.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月17日 星期二 15时35分58秒
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

int treeDiameter(vector<vector<int>>& edges) {
  int n = edges.size() + 1;
  vector<vector<int>> graph(n, vector<int>(0));
  for (auto && e : edges) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  int ans = 0;
  function<int(int, int)> dfs = [&](int cur, int fa) -> int {
    int mmax_1 = 0, mmax_2 = 0;
    for (int nxt : graph[cur]) {
      if (nxt != fa) {
        int t = dfs(nxt, cur);
        if (mmax_1 <= t) {
          mmax_2 = mmax_1;
          mmax_1 = t;
        } else if (mmax_2 <= t) {
          mmax_2 = t;
        }
      }
    }
    ans = max(ans, mmax_1 + mmax_2);
    return mmax_1 + 1;
  };
  dfs(0, -1);
  return ans;
}

int main() {
  return 0;
}
