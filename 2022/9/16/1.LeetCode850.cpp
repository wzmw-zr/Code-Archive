/*************************************************************************
	> File Name: 1.LeetCode850.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月16日 星期五 09时31分42秒
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

// WA
long wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

const long MOD = 1e9 + 7;

struct Point {
  long x;
  long y;
  long type;
  long h;

  Point() = default;
  Point(long x, long y, long type, long h) : x(x), y(y), type(type), h(h) {}

  bool operator<(const struct Point &that) const {
    if (this->x == that.x) 
      return this->type == that.type ? this->y > that.y : this->type > that.type;
    return this->x < that.x;
  }
};


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


set<long> st;
unordered_map<long, long> y2ind;
unordered_map<long, long> ind2y;


struct SegTree {
  struct Node *_root;

  SegTree() = default;
  SegTree(long left, long right) : _root(new Node(left, right)) {}

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
    root->lchild->sum = (root->lchild->sum + root->lazy * (mid - l + 1));
    root->rchild->sum = (root->rchild->sum + root->lazy * (r - mid));
    root->lazy = 0;
    return ;
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
      root->lazy = root->lazy + val;
      root->sum = root->sum + val * (r - l + 1);
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
    long ans = 0;
    long mid = (l + r) / 2;
    if (s <= mid)
      ans = ans + query(root->lchild, s, t);
    if (t > mid)
      ans = ans + query(root->rchild, s, t);
    push_up(root);
    return ans;
  }

  long query(long s, long t) {
    long ans = 0;
    for (long i = s; i < t; i++) {
      long val = query(_root, i, i) == 0 ? 0 : 1;
      ans = ans + val * (ind2y[i + 1] - ind2y[i] + 1);
    }
    return ans;
  }
};

int rectangleArea(vector<vector<int>>& rectangles) {
  long n = rectangles.size();
  vector<Point> points;
  for (long i = 0; i < n; i++) {
    long x1 = rectangles[i][0], y1 = rectangles[i][1];
    long x2 = rectangles[i][2], y2 = rectangles[i][3];
    points.push_back(Point(x1, y1, 0, y2 - y1));
    points.push_back(Point(x2, y2, 1, y2 - y1));
    st.insert(y1);
    st.insert(y2 - 1);
  }
  st.insert(*st.rbegin() + 1);
  sort(points.begin(), points.end());
  int ind = 0;
  for (int x : st) {
    y2ind[x] = ind;
    ind2y[ind] = x;
    ind++;
  }
  SegTree segtree(0, ind - 1);

  long pre_x = points[0].x;
  long ans = 0;
  for (auto && point : points) {
    long x = point.x, y = point.y, type = point.type, h = point.h;
    long dis = x - pre_x;
    long area = dis * segtree.query(0, ind - 1);
    ans = ans + area;
    if (type == 0) 
      segtree.update(y2ind[y], y2ind[y + h - 1], 1);
    else
      segtree.update(y2ind[y - h], y2ind[y - 1], -1);
    pre_x = x;
  }
  return ans % MOD;
}

int main() {
  return 0;
}
