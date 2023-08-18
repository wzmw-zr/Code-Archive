/*************************************************************************
	> File Name: 2.LeetCode2812.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月18日 星期五 14时59分18秒
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
#include <cstdint>
using namespace std;

using PII = pair<int, int>;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int calculate(vector<vector<int>> &dist, int val) {
  int n = dist.size();
  vector<vector<int>> check(n, vector<int>(n, 0));
  queue<PII> que;
  que.push(PII(0, 0));
  check[0][0] = 1;
  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      auto [x, y] = que.front();
      if ((x == n - 1) && (y == n - 1))
        return true;
      que.pop();
      for (int j = 0; j < 4; j++) {
        int x_t = x + dir[j][0];
        int y_t = y + dir[j][1];
        if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= n || check[x_t][y_t] || dist[x_t][y_t] < val)
          continue;
        if ((x_t == n - 1) && (y_t == n - 1))
          return true;
        check[x_t][y_t] = 1;
        que.push(PII(x_t, y_t));
      }
    }
  }
  return false;
}

int maximumSafenessFactor(vector<vector<int>>& grid) {
  int n = grid.size();
  vector<vector<int>> check(n, vector<int>(n, 0));
  vector<vector<int>> dist(n, vector<int>(n, INT32_MAX));
  queue<PII> que;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j]) {
        check[i][j] = 1;
        dist[i][j] = 0;
        que.push(PII(i, j));
      }
    }
  }
  while (!que.empty()) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      auto [x, y] = que.front();
      que.pop();
      for (int j = 0; j < 4; j++) {
        int x_t = x + dir[j][0];
        int y_t = y + dir[j][1];
        if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= n || check[x_t][y_t])
          continue;
        check[x_t][y_t] = 1;
        dist[x_t][y_t] = dist[x][y] + 1;
        que.push(PII(x_t, y_t));
      }
    }
  }
  int l = 0, r = dist[0][0];
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (calculate(dist, mid))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}
