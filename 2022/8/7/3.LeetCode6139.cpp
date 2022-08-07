/*************************************************************************
	> File Name: 3.LeetCode6139.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月07日 星期日 10时33分33秒
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

int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
  vector<vector<int>> graph(n, vector<int>(0));
  for (auto && edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  unordered_set<int> st(restricted.begin(), restricted.end());
  int ans = 0;
  vector<int> check(n, 0);
  queue<int> que;
  que.push(0);
  check[0] = 1;
  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      int ind = que.front();
      que.pop();
      ans++;
      for (int next_ind : graph[ind]) {
        if (check[next_ind] || st.count(next_ind)) continue;
        check[next_ind] = 1;
        que.push(next_ind);
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
