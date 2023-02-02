/*************************************************************************
	> File Name: 1.LeetCode1129.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月02日 星期四 10时48分28秒
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
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
  vector<vector<int>> next;

  Node() : next(vector<vector<int>>(2, vector<int>(0))) {}
};

using TIII = tuple<int, int, int>;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
  vector<Node> graph(n);
  for (auto && e : redEdges)
    graph[e[0]].next[0].push_back(e[1]);
  for (auto && e : blueEdges)
    graph[e[0]].next[1].push_back(e[1]);

  vector<vector<int>> mp(n, vector<int>(2, INT32_MAX));
  queue<TIII> que;
  que.push(TIII(0, 0, 1));
  que.push(TIII(0, 0, 0));
  while (!que.empty()) {
    auto [ind, step, color] = que.front();
    que.pop();
    if (step >= mp[ind][color])
      continue;
    mp[ind][color] = step;
    for (auto && next : graph[ind].next[color ^ 1]) {
      if ((step + 1) >= mp[next][color ^ 1])
        continue;
      que.push(TIII(next, step + 1, color ^ 1));
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
    ans[i] = min(mp[i][0], mp[i][1]) == INT32_MAX ? -1 : min(mp[i][0], mp[i][1]);
  return ans;
}

int main() {
  return 0;
}
