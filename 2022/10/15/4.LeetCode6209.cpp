/*************************************************************************
	> File Name: 4.LeetCode6209.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月15日 星期六 22时46分09秒
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

long MOD = 1e9 + 7;

int max_two_pow(int n) {
  long ans = 1;
  while (ans <= n) {
    if (ans * 2 > n) 
      return ans;
    ans *= 2;
  }
  return ans;
}

struct SegTree {
  int n;
  vector<long> vals;
  vector<long> lazy;

  SegTree() = default;
  SegTree(int n) : n(n), vals(4 * n + 20, 1), lazy(4 * n + 20, 1) {}

  void push_down(int ind, int l, int r) {
    if (l == r)
      return ;
    vals[ind * 2 + 1] = (vals[ind * 2 + 1] * lazy[ind]) % MOD;
    vals[ind * 2 + 2] = (vals[ind * 2 + 2] * lazy[ind]) % MOD;
    lazy[ind * 2 + 1] = (lazy[ind * 2 + 1] * lazy[ind]) % MOD;
    lazy[ind * 2 + 2] = (lazy[ind * 2 + 2] * lazy[ind]) % MOD;
    lazy[ind] = 1;
  }

  void push_up(int ind, int l, int r) {
    if (l == r)
      return ;
    vals[ind] = (vals[ind * 2 + 1] * vals[ind * 2 + 2]) % MOD;
  }

  void update(int ind, int l, int r, int s, int t, int val) {
    if (l > t || r < s)
      return ;
    if (l >= s && r <= t) {
      vals[ind] = (vals[ind] * val) % MOD;
      lazy[ind] = (lazy[ind] * val) % MOD;
      return ;
    }
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    if (s <= mid)
      update(ind * 2 + 1, l, mid, s, t, val);
    if (t > mid)
      update(ind * 2 + 2, mid + 1, r, s, t, val);
    push_up(ind, l, r);
  }

  void update(int s, int t, int val) {
    update(0, 0, n, s, t, val);
  }

  long query(int ind, int l, int r, int s, int t) {
    if (l > r || r < s)
      return 1;
    if (l >= s && r <= t)
      return vals[ind];
    push_down(ind, l, r);
    long ans = 1;
    int mid = (l + r) / 2;
    if (s <= mid)
      ans = (ans * query(ind * 2 + 1, l, mid, s, t)) % MOD;
    if (t > mid)
      ans = (ans * query(ind * 2 + 2, mid + 1, r, s, t)) % MOD;
    push_up(ind, l, r);
    return ans;
  }

  long query(int s, int t) {
    return query(0, 0, n, s, t);
  }
};

vector<int> productQueries(int n, vector<vector<int>>& queries) {
  vector<int> powers;
  while (n) {
    int val = max_two_pow(n);
    powers.push_back(val);
    n -= val;
  }
  reverse(powers.begin(), powers.end());
  int len = powers.size();
  SegTree segtree(len);
  for (int i = 0; i < len; i++) 
    segtree.update(i, i, powers[i]);
  vector<int> ans;
  for (auto && q : queries) 
    ans.push_back(segtree.query(q[0], q[1]));
  return ans;
}

int main() {
  return 0;
}
