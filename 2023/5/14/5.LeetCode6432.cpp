/*************************************************************************
	> File Name: 5.LeetCode6432.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月14日 星期日 10时56分45秒
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
#include <numeric>
using namespace std;

struct UnionSet {
  int n;
  vector<int> fa;

  UnionSet() = default;
  UnionSet(int n) : n(n), fa(vector<int>(n, 0)) {
    iota(fa.begin(), fa.end(), 0);
  }

  int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
  }

  void merge(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b)
      return;
    fa[a] = b;
  }
};

int countCompleteComponents(int n, vector<vector<int>>& edges) {
  UnionSet u(n);
  vector<int> cnts(n, 0);
  for (auto && e : edges) {
    u.merge(e[0], e[1]);
    cnts[e[0]]++, cnts[e[1]]++;
  }
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int fa = u.get(i);
    if (!mp.count(fa))
      mp[fa] = vector<int>();
    mp[fa].push_back(i);
  }
  int ans = 0;
  for (auto && [fa, nodes] : mp) {
    int flag = 1;
    for (int x : nodes) {
      if (cnts[x] + 1 == nodes.size())
        continue;
      flag = 0;
      break;
    }
    ans += flag;
  }
  return ans;
}

int main() {
  return 0;
}
