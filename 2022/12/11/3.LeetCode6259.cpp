/*************************************************************************
	> File Name: 3.LeetCode6259.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月11日 星期日 10时54分02秒
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

// TLE
int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct SegTree {
  vector<int> vals;
  vector<int> lazy;
  int n;

  SegTree(int n) : n(n), vals(vector<int>(4 * n + 10, 0)), lazy(vector<int>(4 * n + 10, 0)) {}

  void push_down(int ind, int l, int r) {
    if (l == r)
      return ;
    int mid = (l + r) / 2;
    vals[ind * 2 + 1] += (mid - l + 1) * lazy[ind];
    vals[ind * 2 + 2] += (r - mid) * lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    lazy[ind * 2 + 2] += lazy[ind];
    lazy[ind] = 0;
  }

  void push_up(int ind, int l, int r) {
    if (l == r)
      return ;
    vals[ind] = vals[ind * 2 + 1] + vals[ind * 2 + 2];
  }

  int query(int ind, int l, int r, int s, int t) {
    if (t < l || s > r)
      return 0;
    if (l >= s && r <= t)
      return vals[ind];
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    int ans = 0;
    if (s <= mid)
      ans += query(ind * 2 + 1, l, mid, s, t);
    if (t > mid)
      ans += query(ind * 2 + 2, mid + 1, r, s, t);
    push_up(ind, l, r);
    return ans;
  }

  int query(int s, int t) {
    return query(0, 0, n - 1, s, t);
  }

  void update(int ind, int l, int r, int s, int t, int val) {
    if (r < s || l > t)
      return ;
    if (l >= s && r <= t) {
      vals[ind] += (r - l + 1) * val;
      lazy[ind] += val;
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
    return update(0, 0, n - 1, s, t, val);
  }
};

using PII = pair<int, int>;

class Allocator {
public:
  int n;
  SegTree segtree;
  unordered_map<int, vector<PII>> mp;

  Allocator(int n) : n(n), segtree(SegTree(n)), mp(unordered_map<int, vector<PII>>()) {}

  int allocate(int size, int mID) {
    for (int i = 0; i <= n - size; i++) {
      if (segtree.query(i, i + size - 1))
        continue;
      segtree.update(i, i + size - 1, 1);
      if (!mp.count(mID))
        mp[mID] = vector<PII>();
      mp[mID].push_back(PII(i, i + size - 1));
      return i;
    }
    return -1;
  }

  int free(int mID) {
    if (!mp.count(mID))
      return 0;
    int ans = 0;
    for (auto && range : mp[mID]) {
      int l = range.first, r = range.second;
      segtree.update(l, r, -1);
      ans += r - l + 1;
    }
    mp.erase(mID);
    return ans;
  }
};

int main() {
  return 0;;
}
