/*************************************************************************
	> File Name: 1.LeetCode1706.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月24日 星期四 00时08分58秒
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

#define LEFT -1
#define RIGHT 1

vector<int> findBall(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int x = 0, y = i;
    int pos = grid[x][y];
    while (1) {
      if (pos == LEFT) {
        if (grid[x][y] == 1) {
          x++;
          if (x == m) {
            ans[i] = y;
            break;
          }
          if (grid[x][y] == 1) {
            pos = RIGHT;
          } else {
            pos = LEFT;
          }
        } else {
          y--;
          if (y < 0 || grid[x][y] == 1) {
            ans[i] = -1;
            break;
          }
          pos = RIGHT;
        }
      } else {
        if (grid[x][y] == 1) {
          y++;
          if (y == n || grid[x][y] == -1) {
            ans[i] = -1;
            break;
          }
          pos = LEFT;
        } else {
          x++;
          if (x == m) {
            ans[i] = y;
            break;
          }
          if (grid[x][y] == 1) {
            pos = RIGHT;
          } else {
            pos = LEFT;
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  return 0;
}
