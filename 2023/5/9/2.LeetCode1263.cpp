/*************************************************************************
	> File Name: 2.LeetCode1263.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月09日 星期二 09时45分14秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node {
  int bx;
  int by;
  int sx;
  int sy;
  int step;

  Node() = default;
  Node(int bx, int by, int sx, int sy, int step) : bx(bx), by(by), sx(sx), sy(sy), step(step) {}
};

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

using PII = pair<int, int>;

int can_reach(vector<vector<char>> &grid, int sx, int sy, int tx, int ty) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> check(m, vector<int>(n, 0));
  queue<PII> que;
  que.push(PII(sx, sy));
  check[sx][sy] = 1;

  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      auto [x, y] = que.front();
      if (x == tx && y == ty)
        return 1;
      que.pop();
      for (int j = 0; j < 4; j++) {
        int x_t = x + dir[j][0];
        int y_t = y + dir[j][1];
        if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || check[x_t][y_t] || grid[x_t][y_t] != '.')
          continue;
        que.push(PII(x_t, y_t));
        check[x_t][y_t] = 1;
      }
    }
  }
  return 0;
}

int minPushBox(vector<vector<char>>& grid) {
  int m = grid.size(), n = grid[0].size();
  int bx, by, sx, sy, tx, ty;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'B') {
        bx = i, by = j;
        grid[i][j] = '.';
      }
      if (grid[i][j] == 'S') {
        sx = i, sy = j;
        grid[i][j] = '.';
      }
      if (grid[i][j] == 'T') {
        tx = i, ty = j;
        grid[i][j] = '.';
      }
    }
  }

  int check[m][n][m][n];
  memset(check, 0, sizeof(check));

  queue<Node> que;
  que.push(Node(bx, by, sx, sy, 0));
  check[bx][by][sx][sy] = 1;

  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      Node node = que.front();
      que.pop();
      if (node.bx == tx && node.by == ty)
        return node.step;
      for (int j = 0; j < 4; j++) {
        int x_t = node.bx + dir[j][0];
        int y_t = node.by + dir[j][1];
        if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || grid[x_t][y_t] == '#')
          continue;

        int bx_t = node.bx - dir[j][0];
        int by_t = node.by - dir[j][1];
        if (bx_t < 0 || bx_t >= m || by_t < 0 || by_t >= n || grid[bx_t][by_t] == '#' || check[bx_t][by_t][node.bx][node.by])
          continue;

        grid[node.bx][node.by] = 'B';
        if (can_reach(grid, node.sx, node.sy, x_t, y_t)) {
          que.push(Node(bx_t, by_t, node.bx, node.by, node.step + 1));
          check[bx_t][by_t][node.bx][node.by] = 1;
        }
        grid[node.bx][node.by] = '.';
      }
    }
  }
  return -1;
}

int main() {
  return 0;
}
