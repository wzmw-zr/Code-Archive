/*************************************************************************
	> File Name: 1.LeetCode1728.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月10日 星期二 09时22分42秒
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

// TlE (maybe use static array, reduce the complexity of state can pass)
using PII = pair<int, int>;
using PSI = pair<string, int>;

bool dfs(string &grid, map<PSI, bool> &mp, int row, int col, PII cat, PII mouse, PII food, int catJump, int mouseJump, int step) {
  if (step > 2000) return false;
  if (cat == mouse) return false;
  if (cat == food) return false;
  if (mouse == food) return true;
  PSI state = PSI(grid, step);
  if (mp.count(state)) return mp[state];
  if (step & 1) {
    for (int i = mouse.second + 1, j = 0; i < col && j < mouseJump; i++, j++) {
      if (grid[mouse.first * col + i] == '#') break;
      if (grid[mouse.first * col + i] == 'C') continue;
      grid[mouse.first * col + mouse.second] = '.';
      grid[mouse.first * col + i] = 'M';
      bool res = dfs(grid, mp, row, col, cat, PII(mouse.first, i), food, catJump, mouseJump, step + 1);
      grid[mouse.first * col + mouse.second] = 'M';
      grid[mouse.first * col + i] = '.';
      if (res) {
        mp[state] = true;
        return true;
      }
    }
    for (int i = mouse.second - 1, j = 0; i >= 0 && j < mouseJump; i--, j++) {
      if (grid[mouse.first * col + i] == '#') break;
      if (grid[mouse.first * col + i] == 'C') continue;
      grid[mouse.first * col + mouse.second] = '.';
      grid[mouse.first * col + i] = 'M';
      bool res = dfs(grid, mp, row, col, cat, PII(mouse.first, i), food, catJump, mouseJump, step + 1);
      grid[mouse.first * col + mouse.second] = 'M';
      grid[mouse.first * col + i] = '.';
      if (res) {
        mp[state] = true;
        return true;
      }
    }
    for (int i = mouse.first + 1, j = 0; i < row && j < mouseJump; i++, j++) {
      if (grid[i * col + mouse.second] == '#') break;
      if (grid[i * col + mouse.second] == 'C') continue;
      grid[mouse.first * col + mouse.second] = '.';
      grid[i * col + mouse.second] = 'M';
      bool res = dfs(grid, mp, row, col, cat, PII(i, mouse.second), food, catJump, mouseJump, step + 1);
      grid[mouse.first * col + mouse.second] = 'M';
      grid[i * col + mouse.second] = '.';
      if (res) {
        mp[state] = true;
        return true;
      }
    }
    for (int i = mouse.first - 1, j = 0; i >= 0 && j < mouseJump; i--, j++) {
      if (grid[i * col + mouse.second] == '#') break;
      if (grid[i * col + mouse.second] == 'C') continue;
      grid[mouse.first * col + mouse.second] = '.';
      grid[i * col + mouse.second] = 'M';
      bool res = dfs(grid, mp, row, col, cat, PII(i, mouse.second), food, catJump, mouseJump, step + 1);
      grid[mouse.first * col + mouse.second] = 'M';
      grid[i * col + mouse.second] = '.';
      if (res) {
        mp[state] = true;
        return true;
      }
    }
    if (dfs(grid, mp, row, col, cat, mouse, food, catJump, mouseJump, step + 1)) {
      mp[state] = true;
      return true;
    }
    mp[state] = false;
    return false;
  } else {
    for (int i = cat.second + 1, j = 0; i < col && j < catJump; i++, j++) {
      if (grid[cat.first * col + i] == '#') break;
      if (grid[cat.first * col + i] == 'M') {
        mp[state] = false;
        return false;
      }
      grid[cat.first * col + cat.second] = '.';
      grid[cat.first * col + i] = 'C';
      bool res = dfs(grid, mp, row, col, PII(cat.first, i), mouse, food, catJump, mouseJump, step + 1);
      grid[cat.first * col + cat.second] = 'C';
      grid[cat.first * col + i] = '.';
      if (!res) {
        mp[state] = false;
        return false;
      }
    }
    for (int i = cat.second - 1, j = 0; i >= 0 && j < catJump; i--, j++) {
      if (grid[cat.first * col + i] == '#') break;
      if (grid[cat.first * col + i] == 'M') {
        mp[state] = false;
        return false;
      }
      grid[cat.first * col + cat.second] = '.';
      grid[cat.first * col + i] = 'C';
      bool res = dfs(grid, mp, row, col, PII(cat.first, i), mouse, food, catJump, mouseJump, step + 1);
      grid[cat.first * col + cat.second] = 'C';
      grid[cat.first * col + i] = '.';
      if (!res) {
        mp[state] = false;
        return false;
      }
    }
    for (int i = cat.first + 1, j = 0; i < row && j < catJump; i++, j++) {
      if (grid[i * col + cat.second] == '#') break;
      if (grid[i * col + cat.second] == 'M') {
        mp[state] = false;
        return false;
      }
      grid[cat.first * col + cat.second] = '.';
      grid[i * col + cat.second] = 'C';
      bool res = dfs(grid, mp, row, col, PII(i, cat.second), mouse, food, catJump, mouseJump, step + 1);
      grid[cat.first * col + cat.second] = 'C';
      grid[i * col + cat.second] = '.';
      if (!res) {
        mp[state] = false;
        return false;
      }
    }
    for (int i = cat.first - 1, j = 0; i >= 0 && j < catJump; i--, j++) {
      if (grid[i * col + cat.second] == '#') break;
      if (grid[i * col + cat.second] == 'M') {
        mp[state] = false;
        return false;
      }
      grid[cat.first * col + cat.second] = '.';
      grid[i * col + cat.second] = 'C';
      bool res = dfs(grid, mp, row, col, PII(i, cat.second), mouse, food, catJump, mouseJump, step + 1);
      grid[cat.first * col + cat.second] = 'C';
      grid[i * col + cat.second] = '.';
      if (!res) {
        mp[state] = false;
        return false;
      }
    }
    if (!dfs(grid, mp, row, col, cat, mouse, food, catJump, mouseJump, step + 1)) {
      mp[state] = false;
      return false;
    }
    mp[state] = true;
    return true;
  }
  return true;
}

bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
  int row = grid.size(), col = grid[0].size();
  PII cat(0, 0), mouse(0, 0), food(0, 0);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 'C') cat.first = i, cat.second = j;
      if (grid[i][j] == 'M') mouse.first = i, mouse.second = j;
      if (grid[i][j] == 'F') food.first = i, food.second = j;
    }
  }
  string zip_grid = "";
  for (auto &s : grid) zip_grid += s;
  map<PSI, bool> mp;
  return dfs(zip_grid, mp, row, col, cat, mouse, food, catJump, mouseJump, 1);
}

int main() {
  return 0;
}
