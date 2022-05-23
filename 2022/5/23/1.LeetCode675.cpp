/*************************************************************************
	> File Name: 1.LeetCode675.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月23日 星期一 09时29分38秒
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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

using PII = pair<int, int>;

int bfs(vector<vector<int>> &forest, int x1, int y1, int x2, int y2) {
  int m = forest.size(), n = forest[0].size();
  vector<vector<int>> check(m, vector<int>(n, 0));
  queue<PII> que;
  int step = 0;
  que.push(PII(x1, y1));
  check[x1][y1] = 1;
  while (!que.empty()) {
    int sz = que.size();
    for (int i = 0; i < sz; i++) {
      auto [tx, ty] = que.front();
      que.pop();
      if (tx == x2 && ty == y2) return step;
      for (int i = 0; i < 4; i++) {
        int x = tx + dir[i][0];
        int y = ty + dir[i][1];
        if (x < 0 || x >= m || y < 0 || y >= n || forest[x][y] == 0 || check[x][y]) continue;
        que.push(PII(x, y));
        check[x][y] = 1;
        if (x == x2 && y == y2) return step + 1;
      }
    }
    step++;
  }
  return -1;
}

int cutOffTree(vector<vector<int>>& forest) {
  int m = forest.size(), n = forest[0].size();
  if (forest[0][0] == 0) return -1;
  vector<PII> trees;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (forest[i][j] > 1) trees.emplace_back(i, j);
    }
  }
  auto cmp = [&](PII &a, PII &b) -> bool {
    return forest[a.first][a.second] < forest[b.first][b.second];
  };
  sort(trees.begin(), trees.end(), cmp);
  int x = 0, y = 0;
  int steps = 0;
  for (int i = 0; i < trees.size(); i++) {
    int step = bfs(forest, x, y, trees[i].first, trees[i].second);
    if (step == -1) return -1;
    steps += step;
    x = trees[i].first, y = trees[i].second;
  }
  return steps;
}

int main() {
  return 0;
}
