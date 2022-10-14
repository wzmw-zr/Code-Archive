/*************************************************************************
	> File Name: 2.LeetCode294.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月14日 星期五 10时29分30秒
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

int n;
unordered_map<long, bool> mp;

bool dfs(long state) {
  if (mp.count(state))
    return mp[state];
  for (int i = 0; i < n - 1; i++) {
    if (!(state & (1L << i)) || !(state & (1L << (i + 1))))
      continue;
    if (dfs(state - (1L << i) - (1L << (i + 1))))
      continue;
    return mp[state] = true;
  }
  return mp[state] = false;
}

bool canWin(string s) {
  long state = 0;
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '+')
      state |= 1L << i;
  }
  return dfs(state);
}

int main() {
  return 0;
}
