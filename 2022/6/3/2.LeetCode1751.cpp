/*************************************************************************
	> File Name: 2.LeetCode1751.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月03日 星期五 11时11分32秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
  int ind;
  int flag;
  int l;
  int r;
  int val;

  Node() = default;
  Node(int ind, int flag, int l, int r, int val) : ind(ind), flag(flag), l(l), r(r), val(val) {}

  bool operator<(const struct Node &that) const {
    return this->ind == that.ind ? this->flag < that.flag : this->ind < that.ind; 
  }
};

int maxValue(vector<vector<int>>& events, int k) {
  set<int> st;
  for (auto && e : events) {
    st.insert(e[0]);
    st.insert(e[1]);
  }
  int ind = 0;
  unordered_map<int, int> mp;
  for (int x : st) mp[x] = ++ind;
  vector<Node> nodes;
  for (auto && e : events) {
    nodes.push_back(Node(mp[e[0]], 0, mp[e[0]], mp[e[1]], e[2]));
    nodes.push_back(Node(mp[e[1]], 1, mp[e[0]], mp[e[1]], e[2]));
  }
  sort(nodes.begin(), nodes.end());
  int n = nodes.size();
  int dp[ind + 1][k + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (nodes[j].flag) {
        int l = nodes[j].l;
        int r = nodes[j].r;
        dp[r][i] = max({dp[r - 1][i], dp[r][i], dp[l - 1][i - 1] + nodes[j].val});
      } else {
        int l = nodes[j].l;
        dp[l][i] = max(dp[l][i], dp[l - 1][i]);
      }
    }
  }
  return dp[ind][k];
}

int main() {
  return 0;
}
