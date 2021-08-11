/*************************************************************************
	> File Name: 3.LeetCode715.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月11日 星期三 10时32分55秒
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
struct Node {
    int val;
    int lazy;
    int left; 
    int right;
    Node *lchild;
    Node *rchild;

    Node() = default;
    Node(int left, int right) : val(0), lazy(-1), left(left), right(right), lchild(nullptr), rchild(nullptr) {}
};

struct SegTree {
    Node *_root;

    SegTree(int left, int right) : _root(new Node(left, right)) {}

    void push_down(Node *root) {
        if (!root) return ;
        if (!root->lchild) root->lchild = new Node(root->left, (root->left + root->right) / 2);
        if (!root->rchild) root->rchild = new Node((root->left + root->right) / 2 + 1, root->right);
        if (root->lazy == -1) return ;
        root->lchild->val = (root->lchild->right - root->lchild->left + 1)  * root->lazy;
        root->rchild->val = (root->rchild->right - root->rchild->left + 1) * root->lazy;
        root->lchild->lazy = root->lazy;
        root->rchild->lazy = root->lazy;
        root->lazy = -1;
    }

    void push_up(Node *root) {
        if (!root) return ;
        root->val = root->lchild->val + root->rchild->val;
    }

    void update(Node *root, int left, int right, int val) {
        if (!root) return ;
        if (root->left > right || root->right < left) return ;
        if (root->left >= left && root->right <= right) {
            root->val = (root->right - root->left + 1) * val;
            root->lazy = val;
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
        int res = 0;
        if (left <= mid) res += query(root->lchild, left, right);
        if (right > mid) res += query(root->rchild, left, right);
        return res;
    }
    
    int query(int left, int right) {
        return query(_root, left, right);
    }
};

class RangeModule {
public:
    SegTree seg;
    RangeModule() : seg(SegTree(0, 1e9)) {}

    void addRange(int left, int right) {
        seg.update(left, right - 1, 1);
    }

    bool queryRange(int left, int right) {
        return seg.query(left, right - 1) == (right - left);
    }

    void removeRange(int left, int right) {
        seg.update(left, right - 1, 0);
    }
};

int main() {
    return 0;
}
