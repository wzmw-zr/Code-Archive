/*************************************************************************
	> File Name: 3.LeetCode1109.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月20日 星期三 21时17分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct Node {
    long left;
    long right;
    long cnt;
    long lazy;
    Node *lchild;
    Node *rchild;
    Node() = default;
    Node(long left, long right) : left(left), right(right), cnt(0), lazy(0), lchild(nullptr), rchild(nullptr) {}
};

Node *build(long left, long right) {
    if (left == right) return new Node(left, right);
    Node *root = new Node(left, right);
    long mid = (left + right) / 2;
    root->lchild = build(left, mid);
    root->rchild = build(mid + 1, right);
    return root;
}

void push_down(Node *root) {
    if (!root || !root->lchild || !root->rchild) return ;
    root->lchild->cnt += (root->lchild->right - root->lchild->left + 1) * root->lazy;
    root->lchild->lazy += root->lazy;
    root->rchild->cnt += (root->rchild->right - root->rchild->left + 1) * root->lazy; 
    root->rchild->lazy += root->lazy;
    root->lazy = 0;
}

void add(Node *root, long left, long right, long cnt) {
    if (!root) return ;
    if (root->left > right || root->right < left) return ;
    if (root->left >= left && root->right <= right) {
        root->cnt += (root->right - root->left + 1) * cnt;
        root->lazy += cnt;
        return ;
    }
    push_down(root);
    add(root->lchild, left, right, cnt);
    add(root->rchild, left, right, cnt);
}

long query(Node *root, long left, long right) {
    if (!root) return 0;
    if (root->left > right || root->right < left) return 0;
    if (root->left >= left && root->right <= right) return root->cnt;
    push_down(root);
    return query(root->lchild, left, right) + query(root->rchild, left, right);
}

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    Node *root = build(1, n);
    vector<int> ans;
    for (auto &x : bookings) add(root, x[0], x[1], x[2]);
    for (int i = 1; i <= n; i++) ans.push_back(query(root, i, i));
    return ans;
}

int main() {
    return 0;
}
