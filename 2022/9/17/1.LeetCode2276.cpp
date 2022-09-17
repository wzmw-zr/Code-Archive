/*************************************************************************
	> File Name: 1.LeetCode2276.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月17日 星期六 18时24分46秒
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

const int MAX_N = 1e9;

struct Node {
  int left;
  int right;
  int lazy;
  int val;
  Node *lchild;
  Node *rchild;

  Node() = default;
  Node(int left, int right) : left(left), right(right), lazy(0), val(0), lchild(nullptr), rchild(nullptr) {}
};

struct SegTree {
  struct Node *_root;

  SegTree() = default;
  SegTree(int left, int right) : _root(new Node(left, right)) {}

  void push_down(Node *root) {
    int l = root->left, r = root->right;
    if (l == r)
      return ;
    int mid = (l + r) / 2;
    if (!root->lchild)
      root->lchild = new Node(l, mid);
    if (!root->rchild)
      root->rchild = new Node(mid + 1, r);
    if (root->lazy) {
      root->lchild->lazy = root->lazy;
      root->rchild->lazy = root->lazy;
      root->lchild->val = mid - l + 1;
      root->rchild->val = r - mid;
      root->lazy = 0;
    }
  }

  void push_up(Node *root) {
    int l = root->left, r = root->right;
    if (l == r)
      return ;
    root->val = root->lchild->val + root->rchild->val;
  }

  void update(Node *root, int s, int t) {
    int l = root->left, r = root->right;
    if (r < s || l > t)
      return ;
    if (l >= s && r <= t) {
      root->lazy = 1;
      root->val = r - l + 1;
      return ;
    }
    push_down(root);
    int mid = (l + r) / 2;
    if (s <= mid)
      update(root->lchild, s, t);
    if (t > mid)
      update(root->rchild, s, t);
    push_up(root);
  }

  void update(int s, int t) {
    update(_root, s, t);
  }

  int query(Node *root, int s, int t) {
    int l = root->left, r = root->right;
    if (r < s || l > t) 
      return 0;
    if (l >= s && r <= t)
      return root->val;
    int mid = (l + r) / 2;
    int ans = 0;
    if (s <= mid)
      ans += query(root->lchild, s, t);
    if (t > mid)
      ans += query(root->rchild, s, t);
    return ans;
  }

  int query(int s, int t) {
    return query(_root, s, t);
  }
};

class CountIntervals {
public:
  SegTree segtree;

  CountIntervals() : segtree(SegTree(1, MAX_N)) {}

  void add(int left, int right) {
    segtree.update(left, right);
  }

  int count() {
    return segtree.query(1, MAX_N);
  }
};

int main() {
  return 0;
}
