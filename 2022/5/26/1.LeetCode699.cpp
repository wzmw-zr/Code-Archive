/*************************************************************************
	> File Name: 1.LeetCode699.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月26日 星期四 09时24分52秒
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

struct SegTree {
  int n;
  vector<int> val;
  vector<int> lazy;
  
  SegTree() = default;
  SegTree(int n) : n(n), val(vector<int>(4 * n + 10, 0)), lazy(vector<int>(4 * n + 10, 0)) {}

  void push_down(int ind, int l, int r) {
    if (l == r) return ;
    if (!lazy[ind]) return ;
    val[ind * 2] = max(val[ind * 2], lazy[ind]);
    val[ind * 2 + 1] = max(val[ind * 2 + 1], lazy[ind]);
    lazy[ind * 2] = max(lazy[ind * 2], lazy[ind]);
    lazy[ind * 2 + 1] = max(lazy[ind * 2 + 1], lazy[ind]);
    lazy[ind] = 0;
    return ;
  }

  void push_up(int ind, int l, int r) {
    if (l == r) return ;
    val[ind] = max(val[ind * 2], val[ind * 2 + 1]);
    return ;
  }

  int query(int s, int t) {
    int l = 1, r = n;
    return query(1, l, r, s, t);
  }

  int query(int ind, int l, int r, int s, int t) {
    if (l > t || r < s) return 0;
    if (l >= s && r <= t) return val[ind];
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    int ans = 0;
    if (s <= mid) ans = max(ans, query(ind * 2, l, mid, s, t));
    if (t > mid) ans = max(ans, query(ind * 2 + 1, mid + 1, r, s, t));
    push_up(ind, l, r);
    return ans;
  }

  void update(int s, int t, int num) {
    int l = 1, r = n;
    update(1, l, r, s, t, num);
  }

  void update(int ind, int l, int r, int s, int t, int num) {
    if (l > t || r < s) return ;
    if (l >= s && r <= t) {
      val[ind] = num;
      lazy[ind] = num;
      return ;
    }
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    if (s <= mid) update(ind * 2, l, mid, s, t, num);
    if (t > mid) update(ind * 2 + 1, mid + 1, r, s, t, num);
    push_up(ind, l, r);
  }
};

vector<int> fallingSquares(vector<vector<int>>& positions) {
  set<int> st;
  for (auto && p : positions) {
    st.insert(p[0]);
    st.insert(p[0] + p[1] - 1);
  }
  int ind = 0;
  unordered_map<int, int> mp;
  for (int x : st) mp[x] = ++ind;
  int n = mp.size();
  SegTree segtree(n + 1);
  vector<int> ans;
  for (auto && p : positions) {
    int l = mp[p[0]], r = mp[p[0] + p[1] - 1];
    int h = segtree.query(l, r);
    segtree.update(l, r, h + p[1]);
    ans.push_back(segtree.query(1, n));
  }
  return ans;
}

int main() {
  return 0;
}
