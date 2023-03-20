/*************************************************************************
	> File Name: 1.LeetCode1012.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月20日 星期一 15时04分42秒
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
#include <functional>
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using T4I = tuple<int, int, int, int>;

int numDupDigitsAtMostN(int n) {
  string num = to_string(n);
  map<T4I, int> mp;
  function<int(int, int, int, int)> dfs = [&](int ind, int isLimited,  int isLeadZero, int mask) {
    if (ind == num.size())
      return isLeadZero ? 0 : 1;
    T4I state(ind, isLimited, isLeadZero, mask);
    if (mp.count(state))
      return mp[state];
    int ans = 0;
    int l = 0, r = isLimited ? num[ind] - '0' : 9;
    for (int i = l; i <= r; i++) {
      if (mask & (1 << i))
        continue;
      ans += dfs(
        ind + 1, 
        isLimited && (i == r), 
        !i && isLeadZero,
        (!i && isLeadZero) ? mask : mask | (1 << i));
    }
    return mp[state] = ans;
  };
  return n - dfs(0, true, true, 0);
}

int main() {
  return 0;
}
