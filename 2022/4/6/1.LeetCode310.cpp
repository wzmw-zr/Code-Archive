/*************************************************************************
	> File Name: 1.LeetCode310.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月06日 星期三 00时21分24秒
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

// WA
int dfs1(vector<vector<int>> &graph, vector<int> &dp1, vector<int> &dp2, vector<int> &check, int ind, int level) {
  if (check[ind]) return -1;
  check[ind] = 1;
  int ans = -1;
  dp1[ind] = level;
  for (int x : graph[ind]) 
    ans = max(ans, dfs1(graph, dp1, dp2, check, x, level + 1));
  dp2[ind] = ans + 1;
  check[ind] = 0;
  return dp2[ind];
}

void dfs2(vector<vector<int>> &graph, vector<int> &dp1, vector<int> &dp2, vector<int> &ans, vector<int> &check, int ind) {
  if (check[ind]) return ;
  check[ind] = 1;
  for (int x : graph[ind]) {
    if (check[x]) continue;
    ans[x] = max(dp1[ind] + 1, dp2[x]);
    dfs2(graph, dp1, dp2, ans, check, x);
  }
  check[ind] = 0;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  vector<vector<int>> graph(n, vector<int>(0));
  for (auto &&e : edges) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  int ind = 0;
  for (int i = 0; i < n; i++) {
    if (graph[i].size() != 1) continue;
    ind = i;
    break;
  }
  vector<int> dp1(n), dp2(n), check(n, 0);
  dfs1(graph, dp1, dp2, check, ind, 0);
  vector<int> ans(n, INT32_MAX);
  ans[ind] = dp2[ind];
  dfs2(graph, dp1, dp2, ans, check, ind);
  return ans;
}

int main() {
  return 0;
}
