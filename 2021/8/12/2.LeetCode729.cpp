/*************************************************************************
	> File Name: 2.LeetCode729.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月12日 星期四 09时29分45秒
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

struct Node {
    int val;
    int lazy;
    int left;
    int right;
    Node *lchild;
    Node *rchild;

    Node() = default;
    Node(int left, int right) : val(0), lazy(0), left(left), right(right), lchild(nullptr), rchild(nullptr) {}
};

struct SegTree {
    Node *_root;

    SegTree(int left, int right) : _root(new Node(left, right)) {}

    void push_down(Node *root) {
        if (!root) return ;
        if (root->left == root->right) return ;
        if (!root->lchild) root->lchild = new Node(root->left, (root->left + root->right) / 2);
        if (!root->rchild) root->rchild = new Node((root->left + root->right) / 2 + 1, root->right);
        if (!root->lazy) return ;
        root->lchild->val += root->lazy;
        root->rchild->val += root->lazy;
        root->lchild->lazy += root->lazy;
        root->rchild->lazy += root->lazy;
        root->lazy = 0;
    }

    void push_up(Node *root) {
        if (!root) return ;
        if (root->left == root->right) return ;
        root->val = max(root->lchild->val, root->rchild->val);
    }

    void update(Node *root, int left, int right, int val) {
        if (!root) return ;
        if (root->right < left || root->left > right) return ;
        if (root->left >= left && root->right <= right) {
            root->val += val;
            root->lazy += val;
            return ;
        }
        push_down(root);
        int mid = (root->left + root->right) / 2;
        if (left <= mid) update(root->lchild, left, right, val);
        if (right > mid) update(root->rchild, left, right, val);
        push_up(root);
    }

    void update(int left, int right, int val) {
        update(_root, left, right, val);
    }

    int query(Node *root, int left, int right) {
        if (root->left > right || root->right < left) return 0;
        if (root->left >= left && root->right <= right) return root->val;
        push_down(root);
        int mid = (root->left + root->right) / 2;
        int ans = 0;
        if (left <= mid) ans = max(ans, query(root->lchild, left, right));
        if (right > mid) ans = max(ans, query(root->rchild, left, right));
        return ans;
    }

    int query(int left, int right) {
        return query(_root, left, right);
    }

};

class MyCalendar {
public:
    SegTree seg;
    MyCalendar() : seg(SegTree(0, 1e9)) {}

    bool book(int start, int end) {
        if (seg.query(start, end - 1)) return false;
        seg.update(start, end - 1, 1);
        return true;
    }
};

int main() {
    return 0;
}
