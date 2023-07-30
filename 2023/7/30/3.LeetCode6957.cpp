/*************************************************************************
	> File Name: 3.LeetCode6957.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月30日 星期日 11时01分26秒
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
#include <tuple>
using namespace std;

long MOD = 1e9 + 7;

using STATE = tuple<int, char, bool, bool>;

map<STATE, long> mp;

long dfs(string &low, string &high, int ind, char c, bool h_limit, bool l_limit, int dis) {
  if (ind == low.size() - 1)
    return 1L;
  STATE state(ind, c, h_limit, l_limit);
  if (mp.count(state))
    return mp[state];
  long ans = 0;
  if (h_limit && l_limit) {
    for (char ch = low[ind + 1]; ch <= high[ind + 1]; ch++) {
      if (abs(int(ch - c)) == 1)
        ans = (ans + dfs(low, high, ind + 1, ch, ch == high[ind + 1], ch == low[ind + 1], dis)) % MOD;
    }
    return mp[state] = ans;
  }
  if (h_limit) {
    for (char ch = '0'; ch <= high[ind + 1]; ch++) {
      if (abs(int(ch - c)) == 1)
        ans = (ans + dfs(low, high, ind + 1, ch, ch == high[ind + 1], false, dis)) % MOD;
    }
    return mp[state] = ans;
  }
  if (l_limit) {
    for (char ch = low[ind + 1]; ch <= '9'; ch++) {
      if (abs(int(ch - c)) == 1 || (c == '0' && ind < dis))
        ans = (ans + dfs(low, high, ind + 1, ch, false, ch == low[ind + 1], dis)) % MOD;
    }
    return mp[state] = ans;
  }
  for (char ch = '0'; ch <= '9'; ch++) {
    if (abs(int(ch - c)) == 1)
      ans = (ans + dfs(low, high, ind + 1, ch, false, false, dis)) % MOD;
  }
  return mp[state] = ans;
}

int countSteppingNumbers(string low, string high) {
  int dis = high.size() - low.size();
  low = string(dis, '0') + low;
  long ans = 0;
  for (char c = low[0]; c <= high[0]; c++) {
    ans = (ans + dfs(low, high, 0, c, c == high[0], c == low[0], dis)) % MOD;
  }
  return ans;
}

int main() {
  return 0;
}
