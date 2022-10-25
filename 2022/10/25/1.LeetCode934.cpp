/*************************************************************************
	> File Name: 1.LeetCode934.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月25日 星期二 09时33分15秒
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

struct Node {
  int x;
  int y;
  int step;

  Node() = default;
  Node(int x, int y, int step) : x(x), y(y), step(step) {}
};

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

using PII = pair<int, int>;

int shortestBridge(vector<vector<int>>& grid) {
  int n = grid.size();
  vector<vector<int>> check(n, vector<int>(n, 0));
  vector<PII> border;
  function<void(int, int)> dfs = [&](int x, int y) {
    check[x][y] = 1;
    int is_border = 0;
    for (int i = 0; i < 4; i++) {
      int x_t = x + dir[i][0];
      int y_t = y + dir[i][1];
      if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= n || check[x_t][y_t])
        continue;
      if (!grid[x_t][y_t]) {
        is_border = 1;
        continue;
      }
      dfs(x_t, y_t);
    }
    if (is_border)
      border.push_back(PII(x, y));
  };
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < n; j++) {
      if (!grid[i][j] || check[i][j])
        continue;
      dfs(i, j);
      flag = 1;
      break;
    }
    if (flag)
      break;
  }
  queue<Node> que;
  for (PII &p : border)
    que.push(Node(p.first, p.second, 0));
  vector<vector<int>> flags(n, vector<int>(n, 0));
  while (!que.empty()) {
    Node temp = que.front();
    que.pop();
    flags[temp.x][temp.y] = 1;
    if (!check[temp.x][temp.y] && grid[temp.x][temp.y])
      return temp.step - 1;
    for (int i = 0; i < 4; i++) {
      int x = temp.x + dir[i][0];
      int y = temp.y + dir[i][1];
      if (x < 0 || x >= n || y < 0 || y >= n || flags[x][y] || check[x][y])
        continue;
      que.push(Node(x, y, temp.step + 1));
      flags[x][y] = 1;
    }
  }
  return -1;
}

int main() {
  return 0;
}
