/*************************************************************************
	> File Name: 1.LeetCode732.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月06日 星期一 09时37分06秒
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
  int left;
  int right;
  int val;
  int lazy;
  Node *lchild;
  Node *rchild;

  Node() = default;
  Node(int left, int right) : left(left), right(right), val(0), lazy(0), lchild(nullptr), rchild(nullptr) {}
};

struct SegTree {
  Node *_root; 

  SegTree() = default;
  SegTree(int n) : _root(new Node(0, n)) {}

  void push_down(Node *root) {
    int l = root->left, r = root->right;
    if (l == r) return ;
    int mid = (l + r) / 2;
    if (!root->lchild) root->lchild = new Node(l, mid);
    if (!root->rchild) root->rchild = new Node(mid + 1, r);
    root->lchild->val += root->lazy;
    root->lchild->lazy += root->lazy;
    root->rchild->val += root->lazy;
    root->rchild->lazy += root->lazy;
    root->lazy = 0;
  }

  void push_up(Node *root) {
    int l = root->left, r = root->right;
    if (l == r) return ;
    int mid = (l + r) / 2;
    root->val = max(root->lchild->val, root->rchild->val);
  }

  void _add(Node *root, int s, int t, int val) {
    int l = root->left, r = root->right;
    if (s > r || t < l) return ;
    if (l >= s && r <= t) {
      root->val += val;
      root->lazy += val;
      return ;
    }
    push_down(root);
    int mid = (l + r) / 2;
    if (s <= mid) _add(root->lchild, s, t, val);
    if (t > mid) _add(root->rchild, s, t, val);
    push_up(root);
  }

  void add(int s, int t, int val) {
    _add(_root, s, t, val);
  }

  int _query(Node *root, int s, int t) {
    int l = root->left, r = root->right;
    if (t < l || s > r) return 0;
    if (l >= s && r <= t) return root->val;
    int ans = 0;
    push_down(root);
    int mid = (l + r) / 2;
    if (s <= mid) ans = max(ans, _query(root->lchild, s, t));
    if (t > mid) ans = max(ans, _query(root->rchild, s, t));
    push_up(root);
    return ans;
  }

  int query(int s, int t) {
    return _query(_root, s, t);
  }
};

class MyCalendarThree {
public:
  SegTree segtree;

  MyCalendarThree() : segtree(SegTree(1e9)) {}

  int book(int start, int end) {
    segtree.add(start, end - 1, 1);
    return segtree.query(0, 1e9);
  }
};


int main() {
  return 0;
}
