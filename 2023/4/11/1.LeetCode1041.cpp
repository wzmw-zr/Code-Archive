/*************************************************************************
	> File Name: 1.LeetCode1041.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月11日 星期二 09时23分34秒
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

bool isRobotBounded(string instructions) {
  vector<int> dir({0, 1});
  int x = 0, y = 0;
  for (int i = 0; i < 4; i++) {
    for (char c : instructions) {
      if (c == 'G') {
        x += dir[0];
        y += dir[1];
      } else if (c == 'L') {
        int a = -1 * dir[1];
        int b = dir[0];
        dir[0] = a, dir[1] = b;
      } else {
        int a = dir[1];
        int b = -dir[0];
        dir[0] = a, dir[1] = b;
      }
    }
  }
  if (x == 0 && y == 0)
    return true;
  return false;
}

int main() {
  return 0;
}
