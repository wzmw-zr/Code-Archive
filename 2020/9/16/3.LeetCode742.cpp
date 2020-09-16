/*************************************************************************
	> File Name: 3.LeetCode742.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月16日 星期三 08时42分26秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
    TreeNode *node;
    bool has_leaf;
    bool contain_target;
    int height;

    Node() = default;
    Node(TreeNode *node, bool has_leaf, bool contain_target, int height)
    : node(node), has_leaf(has_leaf), contain_target(contain_target), height(height) {}
    ~Node() = default;
};


Node findClosestLeaf(TreeNode *root, int k, int &len, TreeNode * &ans) { 
    if (!root) return Node(NULL, false, false, 0);
    if (!root->left && !root->right) {
        if (root->val == k) {
            cout << "find the node : " << k << endl;
            ans = root;
            len = 0;
            return Node(root, true, true, 1);
        }
        return Node(root, true, false, 1);
    }
    auto left = findClosestLeaf(root->left, k, len, ans);
    auto right = findClosestLeaf(root->right, k, len, ans);
    cout << "left : " << left.height << ", right : " << right.height << endl; 
    if (left.contain_target) {
        if (right.has_leaf) {
            if (len > left.height + right.height) {
                len = left.height + right.height;
                ans = right.node;
            } 
        }
        return Node(root, true, true, left.height + 1);
    }
    if (right.contain_target) {
        if (left.has_leaf) {
            if (len > left.height + right.height) {
                len = left.height + right.height;
                ans = left.node;
            } 
        }
        return Node(root, true, true, right.height + 1);
    }
    if (root->val == k) {
        cout << "find the node : " << k << endl;
        if (left.has_leaf) {
            if (len > left.height) {
                len = left.height;
                ans = left.node;
            }
        }
        if (right.has_leaf) {
            if (len > right.height) {
                len = right.height;
                ans = right.node;
            }
        }
        return Node(root, left.has_leaf || right.has_leaf, true, 1);
    }
    int height = INT32_MAX;
    TreeNode *ret = root;
    if (left.has_leaf) {
        if (height > left.height) {
            height = left.height;
            ret = left.node;
        }
    }
    if (right.has_leaf) {
        if (height > right.height) {
            height = right.height;
            ret = right.node;
        }
    }
    return Node(ret, left.has_leaf || right.has_leaf, false, height + 1);
}

int findClosestLeaf(TreeNode* root, int k) {
    int len = INT32_MAX;
    TreeNode *ans = NULL;
    findClosestLeaf(root, k, len, ans);
    cout << (ans ? "Find" : "Miss") << endl;
    return ans->val;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    root->left->left->left->left= new TreeNode(6);
    cout << findClosestLeaf(root, 4) << endl;
    return 0;
}
