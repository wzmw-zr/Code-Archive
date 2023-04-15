/*************************************************************************
	> File Name: 1.LeetCode1042.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月15日 星期六 09时45分09秒
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

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
  vector<vector<int>> graph(n, vector<int>(0));
  vector<int> colors(n, -1);
  for (auto && e : paths) {
    graph[e[0] - 1].push_back(e[1] - 1);
    graph[e[1] - 1].push_back(e[0] - 1);
  }
  for (int i = 0; i < n; i++) {
    unordered_set<int> adj;
    for (int x : graph[i])
      adj.insert(colors[x]);
    for (int color = 1; color <= 4; color++) {
      if (adj.count(color))
        continue;
      colors[i] = color;
      break;
    }
  }
  return colors;
}

int main() {
  return 0;
}
