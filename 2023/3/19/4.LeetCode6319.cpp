/*************************************************************************
	> File Name: 4.LeetCode6319.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月19日 星期日 10时46分47秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

bool checkValidGrid(vector<vector<int>>& grid) {
  int n = grid.size();
  int pos[n * n][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pos[grid[i][j]][0] = i;
      pos[grid[i][j]][1] = j;
    }
  }
  if (pos[0][0] != 0 || pos[0][1] != 0)
    return false;
  for (int i = 1; i < n * n; i++) {
    if (abs(pos[i][0] - pos[i - 1][0]) == 1 && abs(pos[i][1] - pos[i - 1][1]) == 2)
      continue;
    if (abs(pos[i][0] - pos[i - 1][0]) == 2 && abs(pos[i][1] - pos[i - 1][1]) == 1)
      continue;
    return false;
  }
  return true;
}

int main() {
  return 0;
}
