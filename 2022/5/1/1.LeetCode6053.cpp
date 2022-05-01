/*************************************************************************
	> File Name: 1.LeetCode6053.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月01日 星期日 09时57分31秒
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

#define GUARD 2
#define WALL 3

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
  vector<vector<int>> check(m, vector<int>(n, 0));
  for (auto && g : guards) check[g[0]][g[1]] = GUARD;
  for (auto && w : walls) check[w[0]][w[1]] = WALL;
  auto row_to_right = [&](int ind) -> void {
    int guard_can_see = 0;
    for (int i = 0; i < n; i++) {
      if (!check[ind][i]) check[ind][i] = guard_can_see;
      else {
        if (check[ind][i] == GUARD) guard_can_see = 1;
        if (check[ind][i] == WALL) guard_can_see = 0;
      }
    }
  };
  auto row_to_left = [&](int ind) -> void {
    int guard_can_see = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (!check[ind][i]) check[ind][i] = guard_can_see;
      else {
        if (check[ind][i] == GUARD) guard_can_see = 1;
        if (check[ind][i] == WALL) guard_can_see = 0;
      }
    }
  };
  auto col_to_bottom = [&](int ind) -> void {
    int guard_can_see = 0;
    for (int i = 0; i < m; i++) {
      if (!check[i][ind]) check[i][ind] = guard_can_see;
      else {
        if (check[i][ind] == GUARD) guard_can_see = 1;
        if (check[i][ind] == WALL) guard_can_see = 0;
      }
    }
  };
  auto col_to_up = [&](int ind) -> void {
    int guard_can_see = 0;
    for (int i = m - 1; i >= 0; i--) {
      if (!check[i][ind]) check[i][ind] = guard_can_see;
      else {
        if (check[i][ind] == GUARD) guard_can_see = 1;
        if (check[i][ind] == WALL) guard_can_see = 0;
      }
    }
  };
  for (int i = 0; i < m; i++) row_to_right(i), row_to_left(i);
  for (int i = 0; i < n; i++) col_to_bottom(i), col_to_up(i);
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cnt += check[i][j] ? 0 : 1;
    }
  }
  return cnt;
}

int main() {
  return 0;
}
