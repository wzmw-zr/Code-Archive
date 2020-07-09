/*************************************************************************
	> File Name: 1.LeetCode623.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月10日 星期五 00时07分45秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *addOneRow(TreeNode *root, int v, int d, int level) {
    if (!root) return NULL;
    if (level == d - 1) {
        TreeNode *left = new TreeNode(v);
        TreeNode *right = new TreeNode(v);
        left->left = root->left;
        right->right = root->right;
        root->left = left;
        root->right = right;
        return root;
    }
    root->left = addOneRow(root->left, v, d, level + 1);
    root->right = addOneRow(root->right, v, d, level + 1);
    return root;
}

TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
        TreeNode *ret = new TreeNode(v);
        ret->left = root;
        return ret;
    }
    return addOneRow(root, v, d, 1);
}

void output(TreeNode *root) {
    if (!root) return ;
    cout << root->val << " ";
    output(root->left);
    output(root->right);
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);
    root = addOneRow(root, 1, 2);
    output(root);
    return 0;
}
