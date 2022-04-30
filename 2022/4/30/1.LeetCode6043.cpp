/*************************************************************************
	> File Name: 1.LeetCode6043.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月30日 星期六 14时30分30秒
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

vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
  set<int> st;
  unordered_map<int, int> mp;
  for (auto && rec: rectangles) st.insert(rec[0]);
  for (auto && p : points) st.insert(p[0]);
  int ind = 0;
  for (int x: st) mp[x] = ++ind;
  int diff[ind + 10][110];
  memset(diff, 0, sizeof(diff));
  for (auto && rec : rectangles) {
    diff[0][0] += 1;
    diff[0][rec[1] + 1] -= 1;
    diff[mp[rec[0]] + 1][0] -= 1;
    diff[mp[rec[0]] + 1][rec[1] + 1] += 1;
  }
  for (int i = 1; i <= ind; i++) diff[i][0] += diff[i - 1][0];
  for (int i = 1; i <= 105; i++) diff[0][i] += diff[0][i - 1];
  for (int i = 1; i <= ind; i++) {
    for (int j = 1; j <= 105; j++) diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
  }
  vector<int> ans;
  for (auto &&p : points) ans.push_back(diff[mp[p[0]]][p[1]]);
  return ans;
}

int main() {
  return 0;
}
