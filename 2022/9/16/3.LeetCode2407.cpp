/*************************************************************************
	> File Name: 3.LeetCode2407.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月16日 星期五 19时20分23秒
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

const int MAX_N = 1e5 + 10;

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
  SegTree(int n) : _root(new Node(0, n)) {}

  void push_down(Node *root) {
    int l = root->left, r = root->right;
    if (l == r)
      return ;
    int mid = (l + r) / 2;
    if (!root->lchild)
      root->lchild = new Node(l, mid);
    if (!root->rchild)
      root->rchild = new Node(mid + 1, r);
    root->lchild->lazy = max(root->lchild->lazy, root->lazy);
    root->rchild->lazy = max(root->rchild->lazy, root->lazy);
    root->lchild->val = max(root->lchild->val, root->lazy);
    root->rchild->val = max(root->rchild->val, root->lazy);
    root->lazy = 0;
    return ;
  }

  void push_up(Node *root) {
    int l = root->left, r = root->right;
    if (l == r)
      return ;
    root->val = max({root->lchild->val, root->rchild->val, root->val});
  }

  void update(Node *root, int s, int t, int val) {
    int l = root->left, r = root->right;
    if (r < s || l > t)
      return ;
    if (l >= s && r <= t) {
      root->lazy = max(root->lazy, val);
      root->val = max(root->val, val);
      return ;
    }
    push_down(root);
    int mid = (l + r) / 2;
    if (s <= mid)
      update(root->lchild, s, t, val);
    if (t > mid)
      update(root->rchild, s, t, val);
    push_up(root);
  }

  void update(int s, int t, int val) {
    update(_root, s, t, val);
  }

  int query(Node *root, int s, int t) {
    int l = root->left, r = root->right;
    if (r < s || l > t)
      return 0;
    if (l >= s && r <= t)
      return root->val;
    push_down(root);
    int mid = (l + r) / 2;
    int ans = 0;
    if (s <= mid)
      ans = max(ans, query(root->lchild, s, t));
    if (t > mid)
      ans = max(ans, query(root->rchild, s, t));
    push_up(root);
    return ans;
  }

  int query(int s, int t) {
    return query(_root, s, t);
  }
};

int lengthOfLIS(vector<int>& nums, int k) {
  SegTree segtree(MAX_N);
  int ans = 0;
  for (int x : nums) {
    int left = max(0, x - k);
    int right = max(x - 1, 0);
    int len = segtree.query(left, right);
    segtree.update(x, x, len + 1);
    ans = max(ans, len + 1);
  }
  return ans;
}

int main() {
  return 0;
}
