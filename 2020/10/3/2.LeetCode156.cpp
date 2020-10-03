/*************************************************************************
	> File Name: 2.LeetCode156.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月03日 星期六 20时17分55秒
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

    TreeNode() = default;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

#define IS_LEAF(x) (!(x)->left && !(x)->right)

TreeNode *most_left_leaf(TreeNode *root) {
    if (!root) return root;
    if (IS_LEAF(root)) return root;
    return most_left_leaf(root->left);
}

void dfs(TreeNode *root) {
    if (!root) return ;
    if (IS_LEAF(root)) return ;
    dfs(root->left);
    dfs(root->right);
    TreeNode *temp = root->left;
    temp->left = root->right;
    temp->right = root;
    return ;
}

TreeNode* upsideDownBinaryTree(TreeNode* root) {
    TreeNode *ret = most_left_leaf(root);
    dfs(root);
    return ret;
}

int main() {
    return 0;
}
