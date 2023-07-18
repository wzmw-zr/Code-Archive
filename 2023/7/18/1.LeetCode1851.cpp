/*************************************************************************
	> File Name: 1.LeetCode1851.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年07月18日 星期二 09时36分53秒
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
#include <cstdint>
#include <functional>
using namespace std;

struct SegTree {
  vector<int> val;
  vector<int> lazy;
  int n;

  SegTree(int n) : val(vector<int>(4 * n + 10, INT32_MAX)), lazy(vector<int>(4 * n + 10, INT32_MAX)), n(n) {}

  void update(int left, int right, int value) {
    update(0, 0, n, left, right, value);
  }

  void push_down(int ind, int l, int r) {
    if (l == r)
      return ;
    val[ind * 2 + 1] = min(val[ind * 2 + 1], lazy[ind]);
    val[ind * 2 + 2] = min(val[ind * 2 + 2], lazy[ind]);
    lazy[ind * 2 + 1] = min(lazy[ind * 2 + 1], lazy[ind]);
    lazy[ind * 2 + 2] = min(lazy[ind * 2 + 2], lazy[ind]);
    lazy[ind] = INT32_MAX;
  }

  void push_up(int ind, int l, int r) {
    if (l == r)
      return ;
    val[ind] = min({val[ind * 2 + 1], val[ind * 2 + 2]});
  }

  void update(int ind, int l, int r, int s, int t, int value) {
    if (r < s || l > t)
      return ;
    if (l >= s && r <= t) {
      lazy[ind] = min(lazy[ind], value);
      val[ind] = min(val[ind], value);
      return ;
    }
    int mid = (l + r) / 2;
    push_down(ind, l, r);
    if (s <= mid)
      update(ind * 2 + 1, l, mid, s, t, value);
    if (t >= mid + 1)
      update(ind * 2 + 2, mid + 1, r, s, t, value);
    push_up(ind, l, r);
  }

  int query(int ind, int l, int r, int s, int t) {
    if (r < s || l > t)
      return INT32_MAX;
    if (l >= s && r <= t)
      return val[ind];
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    int ans = INT32_MAX;
    if (s <= mid)
      ans = min(ans, query(ind * 2 + 1, l, mid, s, t));
    if (t >= mid + 1)
      ans = min(ans, query(ind * 2 + 2, mid + 1, r, s, t));
    push_up(ind, l, r);
    return ans;
  }
  
  int query(int q) {
    return query(0, 0, n, q, q);
  }
};

vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
  set<int> st;
  for (auto && inter : intervals) {
    st.insert(inter[0]);
    st.insert(inter[1]);
  }
  for (int q : queries)
    st.insert(q);
  unordered_map<int, int> mp;
  int ind = 0;
  for (int x : st)
    mp[x] = ind++;
  SegTree segtree(ind + 10);
  for (auto && inter : intervals) {
    int left = mp[inter[0]];
    int right = mp[inter[1]];
    segtree.update(left, right, inter[1] - inter[0] + 1);
  }
  vector<int> ans;
  for (int q : queries) {
    int val = segtree.query(mp[q]);
    ans.push_back(val == INT32_MAX ? -1 : val);
  }
  return ans;
}

int main() {
  return 0;
}
