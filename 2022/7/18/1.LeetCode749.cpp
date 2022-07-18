/*************************************************************************
	> File Name: 1.LeetCode749.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月18日 星期一 11时34分32秒
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

#define SAFE 0
#define INFECTED 1
#define CLOSE 2

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int containVirus(vector<vector<int>>& isInfected) {
  int m = isInfected.size();
  int n = isInfected[0].size();
  int ans = 0;
  auto pair_hash = [fn = hash<int>()](const pair<int, int> &x) {
    return (fn(x.first) << 16) ^ fn(x.second);
  };
  while (true) {
    vector<vector<int>> check(m, vector<int>(n, 0));
    vector<vector<pair<int, int>>> areas;
    vector<unordered_set<pair<int, int>, decltype(pair_hash)>> neighbours;
    vector<int> perimeters;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (check[i][j]) continue;
        if (isInfected[i][j] != INFECTED) continue;
        queue<pair<int, int>> que;
        unordered_set<pair<int, int>, decltype(pair_hash)> neighbour(0, pair_hash);
        vector<pair<int, int>> area;
        int perimeter = 0;
        que.push({i, j});
        area.push_back({i, j});
        check[i][j] = 1;
        while (!que.empty()) {
          int len = que.size();
          for (int p = 0; p < len; p++) {
            auto [x, y] = que.front();
            que.pop();
            for (int q = 0; q < 4; q++) {
              int x_t = x + dir[q][0];
              int y_t = y + dir[q][1];
              if (x_t < 0 || x_t >= m || y_t < 0 || y_t >= n || check[x_t][y_t] || isInfected[x_t][y_t] == CLOSE) continue;
              if (isInfected[x_t][y_t] == SAFE) {
                perimeter++;
                neighbour.insert({x_t, y_t});
              }
              if (isInfected[x_t][y_t] == INFECTED) {
                area.push_back({x_t, y_t});
                que.push({x_t, y_t});
                check[x_t][y_t] = 1;
              }
            }
          }
        }
        neighbours.push_back(move(neighbour));
        perimeters.push_back(perimeter);
        areas.push_back(area);
      }
    }
    if (neighbours.size() == 0) break;

    int idx = 0;
    for (int i = 0; i < neighbours.size(); i++) {
      if (neighbours[i].size() > neighbours[idx].size()) 
        idx = i;
    }
    ans += perimeters[idx];

    for (auto && [x, y] : areas[idx]) 
      isInfected[x][y] = CLOSE;

    for (int i = 0; i < neighbours.size(); i++) {
      if (i == idx) continue;
      for (auto && [x, y] : neighbours[i]) 
        isInfected[x][y] = INFECTED;
    }

    if (areas.size() == 1) break;
  }
  return ans;
}

int main() {
  return 0;
}
