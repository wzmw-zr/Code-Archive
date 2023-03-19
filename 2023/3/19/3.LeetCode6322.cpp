/*************************************************************************
	> File Name: 3.LeetCode6322.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月19日 星期日 10时36分05秒
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
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int dir[8][2] = {2, 1, 2, -1, -2, 1, -2, -1, 1, 2, 1, -2, -1, 2, -1, -2};

using TIII = tuple<int, int, int>;
bool checkValidGrid(vector<vector<int>>& grid) {
  int n = grid.size();
  map<TIII, bool> mp;
  function<bool(int, int, int)> dfs = [&](int state, int x, int y) -> bool {
    TIII s(state, x, y);
    if (state == (1 << n * n) - 1)
      return mp[s] = true;
    if (mp.count(s))
      return mp[s];
    bool ans = false;
    for (int i = 0; i < 8 && !ans; i++) {
      int x_t = x + dir[i][0]; 
      int y_t = y + dir[i][1];
      if (x_t < 0 || x_t >= n || y_t < 0 || y_t >= n)
        continue;
      if (state & (1 << (x_t * n + y_t)))
        continue;
      ans |= dfs(state | (1 << (x_t * n + y_t)), x_t, y_t);
    }
    return mp[s] = ans;
  };
  return dfs(1, 0, 0);
}

int main() {
  return 0;
}
