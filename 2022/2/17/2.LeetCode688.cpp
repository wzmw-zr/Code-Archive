/*************************************************************************
	> File Name: 2.LeetCode688.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月17日 星期四 00时48分51秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int dir[8][2] = {2, 1, 2, -1, -2, 1, -2, -1, 1, 2, 1, -2, -1, 2, -1, -2};

double knightProbability(int n, int k, int row, int column) {
  double dp[n + 1][n + 1][k + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j][0] = 1.0;
    }
  }
  for (int s = 1; s <= k; s++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int ind = 0; ind < 8; ind++) {
          int x = i + dir[ind][0];
          int y = j + dir[ind][1];
          if (x < 0 || x >= n || y < 0 || y >= n) {
            continue;
          }
          dp[i][j][s] += dp[x][y][s - 1] / 8.0;
        }
      }
    }
  }
  return dp[row][column][k];
}

int main() {
  return 0;
}
