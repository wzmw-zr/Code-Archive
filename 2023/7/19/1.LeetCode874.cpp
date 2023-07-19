/*************************************************************************
	> File Name: 1.LeetCode874.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月19日 星期三 10时08分31秒
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

using PII = pair<int, int>;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
  set<PII> blocked;
  for (auto && obstacle : obstacles)
    blocked.insert(PII(obstacle[0], obstacle[1]));
  int ans = 0;
  vector<int> dir = {0, 1};
  vector<int> pos = {0, 0};
  for (int c : commands) {
    if (c == -2) {
      dir = {-1 * dir[1], dir[0]};
    } else if (c == -1) {
      dir = {dir[1], -1 * dir[0]};
    } else {
      for (int i = 1; i <= c; i++) {
        int x_t = pos[0] + dir[0];
        int y_t = pos[1] + dir[1];
        if (blocked.count(PII(x_t, y_t)))
          break;
        pos = {x_t, y_t};
      }
      ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
    }
  }
  return ans;
}

int main() {
  return 0;
}
