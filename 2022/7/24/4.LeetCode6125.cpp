/*************************************************************************
	> File Name: 4.LeetCode6125.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月24日 星期日 10时34分04秒
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

int equalPairs(vector<vector<int>>& grid) {
  int n = grid.size();
  map<vector<int>, int> mp;
  for (int i = 0; i < n; i++) {
    if (!mp.count(grid[i])) mp[grid[i]] = 0;
    mp[grid[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<int> col;
    for (int j = 0; j < n; j++) 
      col.push_back(grid[j][i]);
    if (mp.count(col)) ans += mp[col];
  }
  return ans;
}

int main() {
  return 0;
}
