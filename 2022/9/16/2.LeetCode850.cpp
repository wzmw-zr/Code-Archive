/*************************************************************************
	> File Name: 2.LeetCode850.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月16日 星期五 14时44分52秒
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

struct Polong {
  long x;
  long y;
  long type;
  long h;

  Polong() = default;
  Polong(long x, long y, long type, long h) : x(x), y(y), type(type), h(h) {}

  bool operator<(const struct Polong &that) const {
    return this->x == that.x ? this->y < that.y : this->x < that.x;
  }
};

unordered_map<long, long> y2ind, ind2y;

struct Node {
  long left;
  long right;
  long lazy;
  long sum;
  Node *lchild;
  Node *rchild;

  Node() = default;
  Node(long left, long right) : left(left), right(right), lazy(0), sum(0), lchild(nullptr), rchild(nullptr) {}
};

struct SegTree {
  struct Node *_root;

  SegTree() = default;
  SegTree(long n) : _root(new Node(0, n - 1)) {}

  void push_down(Node *root) {
    long l = root->left, r = root->right;
    if (l == r)
      return ;
    long mid = (l + r) / 2;
    if (!root->lchild)
      root->lchild = new Node(l, mid);
    if (!root->rchild)
      root->rchild = new Node(mid + 1, r);
    root->lchild->lazy += root->lazy;
    root->rchild->lazy += root->lazy;
    root->lchild->sum += root->lazy * (mid - l + 1);
    root->rchild->sum += root->lazy * (r - mid);
    root->lazy = 0;
  }

  void push_up(Node *root) {
    long l = root->left, r = root->right;
    if (l == r)
      return ;
    root->sum = root->lchild->sum + root->rchild->sum;
  }

  void update(Node *root, long s, long t, long val) {
    long l = root->left, r = root->right;
    if (r < s || l > t)
      return ;
    if (l >= s && r <= t) {
      root->lazy += val;
      root->sum += val * (r - l + 1);
      return ;
    }
    push_down(root);
    long mid = (l + r) / 2;
    if (s <= mid)
      update(root->lchild, s, t, val);
    if (t > mid)
      update(root->rchild, s, t, val);
    push_up(root);
  }

  void update(long s, long t, long val) {
    update(_root, s, t, val);
  }

  long query(Node *root, long s, long t) {
    long l = root->left, r = root->right;
    if (r < s || l > t)
      return 0;
    if (l >= s && r <= t)
      return root->sum;
    push_down(root);
    long mid = (l + r) / 2;
    long ans = 0;
    if (s <= mid)
      ans += query(root->lchild, s, t);
    if (t > mid)
      ans += query(root->rchild, s, t);
    push_up(root);
    return ans;
  }

  long query(long s, long t) {
    long ans = 0;
    for (long i = s; i <= t; i++) {
      long cnt = query(_root, i, i);
      long len = ind2y[i + 1] - ind2y[i];
      ans = ans + (cnt > 0 ? 1 : 0) * len;
    }
    return ans;
  }
};

const long MOD = 1e9 + 7;

class Solution {
public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    set<long> st;
    for (auto && rec : rectangles) {
      st.insert(rec[1]);
      st.insert(rec[3]);
    }
    long ind = 0;
    for (long y : st) {
      y2ind[y] = ind;
      ind2y[ind] = y;
      ind++;
    }
    vector<Polong> polongs;
    for (auto && rec : rectangles) {
      long x1 = rec[0] ,y1 = rec[1], x2 = rec[2], y2 = rec[3];
      polongs.push_back(Polong(x1, y1, 0, y2 - y1));
      polongs.push_back(Polong(x2, y2, 1, y2 - y1));
    }
    sort(polongs.begin(), polongs.end());
    long n = st.size();
    SegTree segtree(n - 1);
    long pre_x = polongs[0].x;
    long ans = 0;
    for (auto && polong : polongs) {
      long x = polong.x, y = polong.y, type = polong.type, h = polong.h;
      long area = segtree.query(0, n - 2);
      ans += area * (x - pre_x);
      if (type == 0) 
        segtree.update(y2ind[y], y2ind[y + h] - 1, 1);
      else
        segtree.update(y2ind[y - h], y2ind[y] - 1, -1);
      pre_x = x;
    }
    return ans % MOD;
  }
};

long main() {
  return 0;
}
