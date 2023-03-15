/*************************************************************************
	> File Name: 1.LeetCode1615.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月15日 星期三 09时37分00秒
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

// TLE
int maximalNetworkRank(int n, vector<vector<int>>& roads) {
  int m = roads.size();
  vector<vector<int>> graph(n, vector<int>(0));
  for (int i = 0; i < m; i++) {
    graph[roads[i][0]].push_back(i);
    graph[roads[i][1]].push_back(i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      unordered_set<int> st(graph[i].begin(), graph[i].end());
      for (int x : graph[j])
        st.insert(x);
      ans = max(ans, static_cast<int>(st.size()));
    }
  }
  return ans;
}

int main() {
  return 0;
}
