/*************************************************************************
	> File Name: 4.LeetCode6135.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月31日 星期日 10时52分16秒
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

int dfs(vector<int> &edges, vector<int> &check, int ind) {
  if (check[ind]) return 0;
  check[ind] = 1;
  return dfs(edges, check, edges[ind]) + 1;
}

int longestCycle(vector<int>& edges) {
  int n = edges.size();
  vector<int> in_degree(n, 0);
  for (int i = 0; i < n; i++) {
    if (edges[i] == -1) 
      continue;
    in_degree[edges[i]]++;
  }
  vector<int> check(n, 0);
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (in_degree[i] == 0) 
      que.push(i);
  }
  while (!que.empty()) {
    int t = que.front();
    que.pop();
    check[t] = 1;
    if (edges[t] == -1) continue;
    if (!(--in_degree[edges[t]])) que.push(edges[t]);
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    if (check[i]) continue;
    ans = max(ans, dfs(edges, check, i));
  }
  return ans;
}

int main() {
  return 0;
}
