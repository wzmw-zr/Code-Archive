/*************************************************************************
	> File Name: 2.LeetCode1615.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月15日 星期三 09时53分52秒
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

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
  vector<unordered_set<int>> graph(n, unordered_set<int>());
  for (auto && road : roads) {
    graph[road[0]].insert(road[1]);
    graph[road[1]].insert(road[0]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans = max(ans, static_cast<int>(graph[i].size() + graph[j].size() - graph[i].count(j)));
    }
  }
  return ans;
}

int main() {
  return 0;
}
