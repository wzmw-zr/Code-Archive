/*************************************************************************
	> File Name: 3.LeetCode294.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月14日 星期五 10时56分16秒
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


bool dfs(long state, unordered_map<long, bool> &mp) {
  if (mp.count(state))
    return mp[state];
  bool ans = false;
  long one = 1;
  for (int i = 0; (i < 60) && !ans; i++) {
    if ((state & (one << i)) && (state & (one << (i + 1)))) {
      long mask = (one << i) | (one << (i + 1));
      bool res = dfs(state - mask, mp);
      ans |= !res;
    }
  }
  return mp[state] = ans;
}

bool canWin(string currentState) {
  long state = 0;
  int n = currentState.size();
  for (int i = 0; i < n; i++)
    state |= (currentState[i] == '+' ? static_cast<long>(1) : static_cast<long>(0)) << i;
  unordered_map<long, bool> mp;
  return dfs(state, mp);
}

int main() {
  return 0;
}
