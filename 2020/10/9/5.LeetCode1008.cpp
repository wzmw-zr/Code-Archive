/*************************************************************************
	> File Name: 5.LeetCode1008.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月09日 星期五 19时42分37秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val == val) return root;
    if (root->val < val) root->right = insert(root->right, val);
    else root->left = insert(root->left, val);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode *root = nullptr;
    for (int i = 0; i < preorder.size(); i++) {
        root = insert(root, preorder[i]);
    }
    return root;
}

int main() {
    return 0;
}
