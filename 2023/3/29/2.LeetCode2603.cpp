/*************************************************************************
	> File Name: 2.LeetCode2603.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月29日 星期三 21时20分36秒
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

struct Node {
  int ind;
  int deg;
  int num_coin;
  unordered_set<int> next;

  Node() = default;
  Node(int ind, int num_coin) : ind(ind), deg(0), num_coin(num_coin), next(unordered_set<int>()) {}

  void add(int id) {
    deg++;
    next.insert(id);
  }

  void erase(int id) {
    if (next.count(id)) {
      deg--;
      next.erase(id);
    }
  }
};

using PII = pair<int, int>;

int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
  int n = coins.size();
  unordered_map<int, Node> mp;
  for (int i = 0; i < n; i++)
    mp[i] = Node(i, coins[i]);
  for (auto && e : edges) {
    mp[e[0]].add(e[1]);
    mp[e[1]].add(e[0]);
  }
  // first topological sort
  queue<int> que;
  for (int i = 0; i < n; i++) {
    if (mp[i].deg == 1 && mp[i].num_coin == 0)
      que.push(i);
  }
  while (!que.empty()) {
    int id = que.front();
    que.pop();
    for (int x : mp[id].next) {
      mp[x].erase(id);
      if (mp[x].deg == 1 && mp[x].num_coin == 0)
        que.push(x);
    }
    mp.erase(id);
  }

  queue<PII> que_t;

  for (auto && [id, node] : mp) {
    if (node.deg == 1)
      que_t.push(PII(id, 0));
  }

  vector<int> levels(n, 0);

  while (!que_t.empty()) {
    PII t = que_t.front();
    que_t.pop();
    int id = t.first, level = t.second;
    levels[id] = level;
    for (int x : mp[id].next) {
      mp[x].erase(id);
      if (mp[x].deg == 1)
        que_t.push(PII(x, level + 1));
    }
    mp.erase(id);
  }

  int ans = 0;
  for (auto && e : edges) {
    if (levels[e[0]] >= 2 && levels[e[1]] >= 2)
      ans += 2;
  }
  return ans;
}

int main() {
  return 0;
}
