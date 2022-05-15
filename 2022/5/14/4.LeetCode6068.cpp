/*************************************************************************
	> File Name: 4.LeetCode6068.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月14日 星期六 22时44分45秒
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

// WA
int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
  sort(tiles.begin(), tiles.end());
  set<int> st;
  for (auto && tile : tiles) {
    st.insert(tile[0]);
    st.insert(tile[1]);
  }
  unordered_map<int, int> mp;
  int ind = 0;
  for (int x : st) mp[x] = ind++;
  vector<int> pre(ind + 1, 0);
  for (auto && tile : tiles) {
    pre[mp[tile[0]] + 1] = pre[mp[tile[0]]];
    pre[mp[tile[1]] + 1] = pre[mp[tile[1]]] + tile[1] - tile[0] + 1;
  }
  int ans = 0;
  for (auto && tile : tiles) {
    auto iter = st.upper_bound(tile[0] + carpetLen - 1);
    iter = prev(iter);
    int cnt = pre[mp[*iter] + 1] - pre[mp[tile[0]]];
    if (mp[*iter] & 1 == 0) cnt += tile[0] + carpetLen - *iter;
    ans = max(ans, cnt);
  }
  return ans;
}

int main() {
  return 0;
}
