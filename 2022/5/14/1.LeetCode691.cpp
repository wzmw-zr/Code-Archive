/*************************************************************************
	> File Name: 1.LeetCode691.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月14日 星期六 09时53分04秒
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
map<vector<int>, int> mp;

int dfs(vector<vector<int>> &cnts, vector<int> state) {
  if (mp.count(state)) return mp[state];
  for (auto &&cnt : cnts) {
    int flag = 1;
    for (int i = 0; i < 26; i++) {
      if (state[i] > cnt[i]) {
        flag = 0;
        break;
      }
    }
    if (flag) return mp[state] = 1;
  }
  int mmin = INT32_MAX;
  for (auto &&cnt : cnts) {
    vector<int> temp = state;
    bool flag = 0;
    for (int i = 0; i < 26; i++) {
      temp[i] = max(temp[i] - cnt[i], 0);
      if (cnt[i] && state[i]) flag = 1;
    }
    if (flag) mmin = min(mmin, 1 + dfs(cnts, temp));
  }
  return mp[state] = mmin;
}

int minStickers(vector<string>& stickers, string target) {
  unordered_set<char> st1, st2;
  for (auto s : stickers) {
    for (auto c : s) st1.insert(c);
  }
  for (auto c : target) st2.insert(c);
  for (auto c : st2) {
    if (st1.count(c)) continue;
    return -1;
  }
  int n = stickers.size();
  vector<vector<int>> cnts(n, vector<int>(26, 0));
  for (int i = 0; i < n; i++) {
    for (char c : stickers[i]) cnts[i][c - 'a']++;
  }
  vector<int> state(26, 0);
  for (char c : target) state[c - 'a']++;
  return dfs(cnts, state);
}

int main() {
  return 0;
}
