/*************************************************************************
	> File Name: 1.LeetCode98.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月05日 星期二 07时30分02秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *GetNewNode(int x) {
    TreeNode *node = (TreeNode *) calloc(sizeof(TreeNode), 1);
    node->val = x;
    return node;
}

TreeNode* predecessor(TreeNode *root) {
    if (!root) return NULL;
    TreeNode *left = root->left;
    while (left && left->right) left = left->right;
    return left;
}

TreeNode* nextdecessor(TreeNode *root) {
    if (!root) return NULL;
    TreeNode *right = root->right;
    while (right && right->left) right = right->left;
    return right;
}

bool Check(TreeNode *root) {
    if (!root) return true;
    TreeNode *left = predecessor(root), *right = nextdecessor(root);
    if (!left && !right) return true;
    if (!left) return root->val < right->val;
    if (!right) return root->val > left->val;
    return root->val < right->val && root->val > left->val;
}

bool isValidBST(TreeNode *root) {
    if (!root) return true;
    bool left = isValidBST(root->left);
    bool right = isValidBST(root->right);
    bool check = Check(root);
    return left && right && check;
}

int main() {
    TreeNode *root = NULL;
    cout << (isValidBST(root) ? "Yes" : "No") << endl;
    return 0;
}
