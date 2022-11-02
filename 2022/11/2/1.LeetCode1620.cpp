/*************************************************************************
	> File Name: 1.LeetCode1620.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月02日 星期三 09时42分43秒
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
#include <cmath>
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using TIII = tuple<int, int, int>;

vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
  int pos[110][110];
  memset(pos, 0, sizeof(pos));
  for (auto & tower : towers) {
    int x = tower[0], y = tower[1], q = tower[2];
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        float d = sqrt(1.0 * pow(i - x, 2) + pow(j - y, 2));
        if (d > radius)
          continue;
        int val = q / (1 + d);
        pos[i][j] += val;
      }
    }
  }
  vector<TIII> nodes;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      nodes.push_back(TIII(pos[i][j], i, j));
    }
  }
  sort(nodes.begin(), nodes.end(), [](TIII &a, TIII &b) {
    auto && [v1, x1, y1] = a;
    auto && [v2, x2, y2] = b;
    if (v1 == v2) 
      return x1 == x2 ? y1 < y2 : x1 < x2;
    return v1 > v2;
  });
  auto [v, x, y] = nodes[0];
  vector<int> ans({x, y});
  return ans;
}

int main() {
  return 0;
}
