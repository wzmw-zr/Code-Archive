/*************************************************************************
	> File Name: 3.SegmentTree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月09日 星期一 14时10分19秒
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
    int l, r, val;
    Node *left, *right;
    Node() = default;
    Node(int l, int r, int val = 0) : l(l), r(r), val(val), left(nullptr), right(nullptr) {}
};

Node *build(int left, int right) {
    Node *root = new Node(left, right);
    if (left == right) return root;
    int mid = (left + right) / 2;
    root->left = build(left, mid);
    root->right = build(mid + 1, right);
    return root;
}

void add(Node *root, int ind, int val) {
    if (!root) return ;
    root->val += val;
    if (root->l == root->r) return ;
    int mid = (root->l + root->r) / 2;
    if (ind <= mid) add(root->left, ind, val);
    else add(root->right, ind, val);
}

int count(Node *root, int left, int right) {
    if (root->l > right || root->r < left) return 0;
    if (root->l >= left && root->r <= right) return root->val;
    return count(root->left, left, right) + count(root->right, left, right);
}

int main() {
    return 0;
}
