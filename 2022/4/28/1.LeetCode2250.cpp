/*************************************************************************
	> File Name: 1.LeetCode2250.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月28日 星期四 18时42分56秒
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

// TLE
vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
  int MAX_H = 110;
  map<int, int> mp[MAX_H + 10];
  for (auto && rec : rectangles) {
    for (int i = 0; i <= rec[1]; i++) {
      mp[i][0] += 1;
      mp[i][rec[0] + 1] += -1;
    }
  }
  for (auto &&p : points) mp[p[1]][p[0]];
  for (int i = 0; i <= MAX_H; i++) {
    int pre = 0;
    for (auto iter = mp[i].begin(); iter != mp[i].end(); iter++) {
      iter->second += pre;
      pre = iter->second;
    }
  }
  vector<int> ans;
  for (auto &&p : points) ans.push_back(mp[p[1]][p[0]]);
  return ans;
}

int main() {
  return 0;
}
