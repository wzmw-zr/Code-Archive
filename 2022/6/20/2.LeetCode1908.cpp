/*************************************************************************
	> File Name: 2.LeetCode1908.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月20日 星期一 16时21分50秒
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

map<vector<int>, bool> mp;

bool nimGame(vector<int>& piles) {
  if (mp.count(piles)) return mp[piles];
  int n = piles.size();
  int flag = 0;
  for (int x : piles) {
    if (x) flag = 1;
  }
  if (!flag) {
    return mp[piles] = false;
  }
  for (int i = 0; i < n; i++) {
    for (int x = 1; x <= piles[i]; x++) {
      piles[i] -= x;
      bool res = nimGame(piles);
      piles[i] += x;
      if (res == false) return mp[piles] = true;
    }
  }
  return mp[piles] = false;
}

int main() {
  return 0;
}
