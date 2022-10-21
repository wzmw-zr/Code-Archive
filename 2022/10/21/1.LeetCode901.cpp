/*************************************************************************
	> File Name: 1.LeetCode901.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月21日 星期五 09时20分24秒
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

// TLE
const int MAX_N = 1e4 + 10;

struct SegTree {
  int n;
  vector<int> vals;
  vector<int> lazy;

  SegTree() = default;
  SegTree(int n) : n(n), vals(vector<int>(4 * n + 10, 0)), lazy(vector<int>(4 * n + 10, 0)) {}

  void push_down(int ind, int l, int r) {
    if (l == r)
      return ;
    vals[ind * 2 + 1] = max(vals[ind * 2 + 1], lazy[ind]);
    vals[ind * 2 + 2] = max(vals[ind * 2 + 2], lazy[ind]);
    lazy[ind * 2 + 1] = max(lazy[ind * 2 + 1], lazy[ind]);
    lazy[ind * 2 + 2] = max(lazy[ind * 2 + 2], lazy[ind]);
    lazy[ind] = 0;
  }

  void push_up(int ind, int l, int r) {
    if (l == r)
      return ;
    vals[ind] = max(vals[ind * 2 + 1], vals[ind * 2 + 2]);
  }

  void update(int ind, int l, int r, int s, int t, int val) {
    if (r < s || l > t)
      return ;
    if (l >= s && r <= t) {
      vals[ind] = val;
      lazy[ind] = val;
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

  int query(int ind, int l, int r, int s, int t) {
    if (l > t || r < s)
      return 0;
    if (l >= s && r <= t) 
      return vals[ind];
    push_down(ind, l, r);
    int mid = (l + r) / 2;
    int ans = 0;
    if (s <= mid)
      ans = max(ans, query(ind * 2 + 1, l, mid, s, t)) ;
    push_up(ind, l, r);
      ans = max(ans, query(ind * 2 + 2, mid + 1, r, s, t));
    return ans;
  }

  int query(int s, int t) {
    return query(0, 0, n, s, t);
  }
};

class StockSpanner {
public:
  SegTree segtree;
  int index;

  StockSpanner() : segtree(MAX_N), index(0) {}

  int next(int price) {
    segtree.update(index, index, price);
    int l = 0, r = index;
    while (l < r) {
      int mid = (l + r) / 2;
      if (segtree.query(mid, index) > price)
        l = mid + 1;
      else
        r = mid;
    }
    index++;
    return index - l;
  }
};

int main() {
  return 0;
}
