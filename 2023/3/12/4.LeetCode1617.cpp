/*************************************************************************
	> File Name: 4.LeetCode1617.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月12日 星期日 11时21分23秒
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

// WA
using PII = pair<int, int>;

vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
  function<void(vector<vector<int>> &, int, set<int> &)> dfs1 = [&](vector<vector<int>> &graph, int ind, set<int> &st) {
    if (st.count(ind))
      return ;
    st.insert(ind);
    for (int next_ind : graph[ind])
      dfs1(graph, next_ind, st);
  };

  function<int(int)> check = [&](int state) -> int {
    if (__builtin_popcount(state) <= 1)
      return 0;
    set<int> inds;
    for (int i = 0; i < n; i++) {
      if (state & (1 << (i + 1)))
        inds.insert(i + 1);
    }
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (auto && e : edges) {
      if (!inds.count(e[0]) || !inds.count(e[1]))
        continue;
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    set<int> result;
    dfs1(graph, *inds.begin(), result);
    return result == inds ? 1 : 0;
  };

  function<PII(vector<vector<int>> &, int, unordered_set<int> &)> dfs2 = [&](vector<vector<int>> &graph, int ind, unordered_set<int> &st) {
    PII ans(ind, 0);
    st.insert(ind);
    for (int x : graph[ind]) {
      if (st.count(x))
        continue;
      PII res = dfs2(graph, x, st);
      if ((res.second + 1) > ans.second) {
        ans = res;
        ans.second += 1;
      }
    }
    return ans;
  };

  function<int(int)> diameter = [&](int state) -> int {
    set<int> inds;
    for (int i = 0; i < n; i++) {
      if (state & (1 << (i + 1)))
        inds.insert(i + 1);
    }
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (auto && e : edges) {
      if (!inds.count(e[0]) || !inds.count(e[1]))
        continue;
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    unordered_set<int> st_1;
    auto && [ind_1, dis_1] = dfs2(graph, *inds.begin(), st_1);
    unordered_set<int> st_2;
    auto && [ind_2, dis_2] = dfs2(graph, ind_1, st_2);
    return dis_2;
  };

  vector<int> ans(n - 1, 0);
  for (int state = (1 << n) - 1; state >= 1; state--) {
    if (!check(state))
      continue;
    ans[diameter(state)]++;
  }
  return ans;
}

int main() {
  return 0;
}
