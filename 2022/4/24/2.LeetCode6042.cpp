/*************************************************************************
	> File Name: 2.LeetCode6042.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月24日 星期日 14时31分08秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int countLatticePoints(vector<vector<int>>& circles) {
  vector<vector<int>> check(210, vector<int>(210, 0));
  int n = circles.size();
  for (int i = 0; i < n; i++) {
    int x = circles[i][0], y = circles[i][1], r = circles[i][2];
    for (int p = x - r; p <= x + r; p++) {
      for (int q = y - r; q <= y + r; q++) {
        if ((p - x) * (p - x) + (q - y) * (q - y) <= r * r) check[p][q] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 200; i++) {
    for (int j = 0; j <= 200; j++) {
      ans += check[i][j];
    }
  }
  return ans;
}

int main() {
  return 0;
}
