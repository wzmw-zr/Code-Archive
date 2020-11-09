/*************************************************************************
	> File Name: 4.SegmentTree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月09日 星期一 14时28分07秒
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
    int left, right, val, flag;
    Node *lchild, *rchild;

    Node() = default;
    Node(int left, int right, int val = 0, int flag = 0) : left(left), right(right), val(val), flag(flag), lchild(nullptr), rchild(nullptr) {} 
};

Node *build(int left, int right) {
    Node *root = new Node(left, right);
    if (left == right) return root;
    int mid = (left + right) / 2;
    root->lchild = build(left, mid);
    root->rchild = build(mid + 1, right);
    return root;
}

void add(Node *root, int ind, int val) {
    if (!root) return ;
    if (root->left == root->right) {
        root->val += val;
        return ;
    }
    root->val += val;
    int mid = (root->left + root->right) / 2;
    if (ind <= mid) add(root->lchild, ind, val);
    else add(root->rchild, ind, val);
}

int modify(Node *root, int left, int right, int val) {
    if (!root) return 0;
    if (root->left > right || root->right < left) return 0;
    if (root->left >= left && root->right <= right) {
        root->val += (right - left + 1) * val;
        root->flag += val;
        return (right - left + 1) * val;
    }
    int add = modify(root->lchild, left, right, val) + modify(root->rchild, left, right, val);
    root->val += add;
    return add;
}

int query(Node *root, int left, int right) {
    if (!root) return 0;
    if (root->left > right || root->right < left) return 0;
    if (root->left == root->right) {
        root->flag = 0;
        return root->val;
    }
    if (root->left >= left && root->right <= right) {
        if (root->lchild) {
            root->lchild->flag += root->flag;   
            root->lchild->val += root->flag * (root->lchild->right - root->lchild->left + 1);
        }
        if (root->rchild) {
            root->rchild->flag += root->flag;   
            root->rchild->val += root->flag * (root->rchild->right - root->rchild->left + 1);
        }
        root->flag = 0;
        return root->val;
    }
    return query(root->lchild, left, right) + query(root->rchild, left, right);
}

int main() {
    return 0;
}
