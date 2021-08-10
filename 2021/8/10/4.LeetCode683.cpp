/*************************************************************************
	> File Name: 4.LeetCode683.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月10日 星期二 15时29分22秒
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
    int left;
    int right;
    int lazy;
    Node *lchild;
    Node *rchild;

    Node() = default;
    Node(int left, int right) : val(0), left(left), right(right), lazy(0), lchild(nullptr), rchild(nullptr) {}
};

struct SegTree {
    Node *_root;

    SegTree(int n) {
        _root = build(1, n);
    }
    
    Node *build(int left, int right) {
        if (left == right) return new Node(left, right);
        Node *root = new Node(left, right);
        int mid = (left + right) / 2;
        root->lchild = build(left, mid);
        root->rchild = build(mid + 1, right);
        return root;
    }

    void push_down(Node *root) {
        if (!root || (root->left == root->right)) return;
        int mid = (root->left + root->right) / 2;
        root->lchild->val += (mid - root->left + 1) * root->lazy;
        root->rchild->val += (root->right - mid) * root->lazy;
        root->lchild->lazy += root->lazy;
        root->rchild->lazy += root->lazy;
        root->lazy = 0;
    }

    void push_up(Node *root) {
        if (!root || (root->left == root->right)) return ;
        root->val = root->lchild->val + root->rchild->val;
    }

    void update(Node *root, int left, int right, int val) {
        if (root->right < left || root->left > right) return ;
        if (root->left >= left && root->right <= right) {
            root->val += (root->right - root->left + 1) * val;
            root->lazy += val;
            return ;
        }
        push_down(root);
        int mid = (root->left + root->right) / 2;
        if (left <= mid) update(root->lchild, left, right, val);
        if (right > mid) update(root->rchild, left, right, val);
        push_up(root);
    }
    
    void update(int ind, int val) {
        update(_root, ind, ind, val);
    }

    int query(Node *root, int left, int right) {
        if (root->right < left || root->left > right) return 0;
        if (root->left >= left && root->right <= right) return root->val;
        push_down(root);
        int mid = (root->left + root->right) / 2;
        int ans = 0;
        if (left <= mid) ans += query(root->lchild, left, right);
        if (right > mid) ans += query(root->rchild, left, right);
        return ans;
    }

    int query(int left, int right) {
        return query(_root, left, right);
    }
};

int kEmptySlots(vector<int>& bulbs, int k) {
    int n = bulbs.size();
    SegTree seg(n);
    for (int i = 0; i < n; i++) {
        seg.update(bulbs[i], 1);
        if ((bulbs[i] >= k + 2) && (seg.query(bulbs[i] - k - 1, bulbs[i]) == 2) && (seg.query(bulbs[i] - k, bulbs[i]) == 1)) return i + 1;
        if ((bulbs[i] <= (n - k - 1)) && (seg.query(bulbs[i], bulbs[i] + k + 1) == 2) && (seg.query(bulbs[i], bulbs[i] + k) == 1)) return i + 1;
    }
    return -1;
}

int main() {
    return 0;
}
