/*************************************************************************
	> File Name: 5.LeetCode6191.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月25日 星期日 18时42分35秒
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
  int val;
  vector<int> next;

  Node() = default;
  Node(int ind, int val) : ind(ind), val(val), next(vector<int>(0)) {}

  bool operator<(const struct Node &that) const {
    return this->val < that.val;
  }
};

struct UnionSet {
  int n;
  vector<int> fa;
  vector<int> cnts;

  UnionSet() = default;
  UnionSet(int n) : n(n), fa(vector<int>(n)), cnts(vector<int>(n, 1)) {
    for (int i = 0; i < n; i++)
      fa[i] = i;
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }
};

int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
  int n = vals.size();
  UnionSet u(n);
  vector<Node> nodes;
  for (int i = 0; i < n; i++) 
    nodes.emplace_back(i, vals[i]);
  for (auto && edge : edges) {
    nodes[edge[0]].next.push_back(edge[1]);
    nodes[edge[1]].next.push_back(edge[0]);
  }
  sort(nodes.begin(), nodes.end());
  vector<int> check(n, 0);
  int ans = 0;
  for (auto && node : nodes) {
    int ind = node.ind;
    check[ind] = 1;
    for (int x : node.next) {
      int b = u.get(x);
      if (!check[b] || ind == b || vals[b] > vals[ind])
        continue;
      if (vals[ind] == vals[b]) {
        ans += u.cnts[ind] * u.cnts[b];
        u.cnts[ind] += u.cnts[b];
      }
      u.fa[b] = ind;
    }
  }
  ans += n;
  return ans;
}

int main() {
  return 0;
}
