/*************************************************************************
	> File Name: 1.LeetCode1079.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月19日 星期五 09时53分33秒
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
using namespace std;

int frac(int n) {
  int ans = 1;
  for (int i = 1; i <= n; i++)
    ans *= i;
  return ans;
}

int calculate(map<char, int> &mp) {
  int n = 0;
  for (auto && [ch, cnt] : mp)
    n += cnt;
  if (n == 0)
    return 0;
  int ans = frac(n);
  for (auto && [ch, cnt] : mp)
    ans /= frac(cnt);
  return ans;
}

int numTilePossibilities(string tiles) {
  map<char, int> mp;
  for (char c : tiles)
    mp[c]++;
  int ans = 0;
  set<map<char, int>> st;

  function<void()> dfs = [&]() {
    if (st.count(mp))
      return;
    st.insert(mp);
    ans += calculate(mp);
    for (auto && [ch, cnt] : mp) {
      if (cnt > 0) {
        mp[ch]--;
        dfs();
        mp[ch]++;
      }
    }
  };

  dfs();
  return ans;
}

int main() {
  return 0;
}
