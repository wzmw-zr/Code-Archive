/*************************************************************************
	> File Name: 3.LeetCode6343.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月30日 星期日 10时51分45秒
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

long wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

// WA
long minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
  set<vector<long>> st;
  st.insert({start[0], start[1]});
  st.insert({target[0], target[1]});
  for (auto && roads : specialRoads) {
    st.insert({roads[0], roads[1]});
    st.insert({roads[2], roads[3]});
  }

  map<vector<long>, long> mp;
  for (auto && roads : specialRoads) {
    vector<long> road1({roads[0], roads[1], roads[2], roads[3]});
    mp[road1] = roads[4];
  }
  
  auto cmp = [&](vector<long> &a, vector<long> &b) -> bool {
    return a[2] > b[2];
  };
  priority_queue<vector<long>, vector<vector<long>>, decltype(cmp)> que(cmp);
  que.push({start[0], start[1], 0});
  while (!que.empty()) {
    auto node = que.top();
    que.pop();
    long x = node[0], y = node[1], cost = node[2];
    if (x == target[0] && y == target[1])
      return cost;
    if (!st.count({x, y}))
      continue;
    st.erase({x, y});
    for (auto && next : st) {
      vector<long> road({x, y, next[0], next[1]});
      if (mp.count(road))
        que.push({next[0], next[1], cost + min(mp[road], abs(next[0] - x) + abs(next[1] - y))});
      else
        que.push({next[0], next[1], cost + abs(next[0] - x) + abs(next[1] - y)});
    }
  }
  return -1;
}

int main() {
  return 0;
}
