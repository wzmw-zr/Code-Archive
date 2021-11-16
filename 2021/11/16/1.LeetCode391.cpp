/*************************************************************************
	> File Name: 1.LeetCode391.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月16日 星期二 12时33分27秒
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


// Wrong Solution

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

    SegTree() : _root(new Node(-1e5 - 10, 1e5 + 10)) {}

    void push_down(Node *root) {
        if (root->left == root->right) return ;
        int mid = (root->left + root->right) / 2;
        if (!root->lchild) root->lchild = new Node(root->left, mid);
        if (!root->rchild) root->rchild = new Node(mid + 1, root->right);
        root->lchild->val += root->lazy * (mid - root->left + 1);
        root->rchild->val += root->lazy * (root->right - mid);
        root->lchild->lazy += root->lazy;
        root->rchild->lazy += root->lazy;
        root->lazy = 0;
    }

    void push_up(Node *root) {
        if (!root) return;
        if (root->left == root->right) return ;
        root->val = root->lchild->val + root->rchild->val;
    }

    void update(Node *root, int s, int t, int val) {
        if (!root) return ;
        if (root->left > t || root->right < s) return ;
        if (root->left >= s && root->right <= t) {
            root->lazy += val;
            root->val += (root->right - root->left + 1) * val;
            return ;
        }
        push_down(root);
        int mid = (root->left + root->right) / 2;
        if (s <= mid) update(root->lchild, s, t, val);
        if (t >= mid + 1) update(root->rchild, s, t, val);
        push_up(root);
    }

    void update(int s, int t, int val) {
        update(_root, s, t, val);
    }

    int query(Node *root, int s, int t) {
        if (!root) return 0;
        if (root->left > t || root->right < s) return 0;
        if (root->left >= s && root->right <= t) return root->val;
        push_down(root);
        int ans = 0;
        int mid = (root->left + root->right) / 2;
        if (s <= mid)  ans += query(root->lchild, s, t);
        if (t >= mid + 1) ans += query(root->rchild, s, t);
        push_up(root);
        return ans;
    }

    int query(int s, int t) {
        return query(_root, s, t);
    }
};

struct WNode {
    int left;
    int right;
    SegTree *root;
    int lazy_l;
    int lazy_r;
    WNode *lchild;
    WNode *rchild;

    WNode() = default;
};

struct SegWSeg {
    WNode *_root;

    SegWSeg() : _root(new WNode()) {}

    void update(int xmin, int ymin, int xmax, int ymax, int val) {
        return ;
    }

    int query(int xmin, int ymin, int xmax, int ymax) {
        return {};
    }
};

bool isRectangleCover(vector<vector<int>>& rectangles) {
    SegWSeg tree;
    int xmin = INT32_MAX, ymin = INT32_MAX, xmax = INT32_MIN, ymax = INT32_MIN;
    for (auto rec : rectangles) {
        tree.update(rec[0], rec[1], rec[2], rec[3], 1);
        xmin = min(rec[0], xmin);
        ymin = min(rec[1], ymin);
        xmax = max(rec[2], xmax);
        ymax = max(rec[3], ymax);
    }
    return tree.query(xmin, ymin, xmax, ymax) == (xmax - xmin) * (ymax - ymin);
    return {};
}

int main() {
    return 0;
}
