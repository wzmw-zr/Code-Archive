/*************************************************************************
	> File Name: 1.LeetCode897.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月25日 星期日 00时03分22秒
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

void dfs(TreeNode *root, vector<TreeNode *> &nodes) {
    if (!root) return ;
    dfs(root->left, nodes);
    nodes.push_back(root);
    dfs(root->right, nodes);
}

TreeNode* increasingBST(TreeNode* root) {
    vector<TreeNode *> nodes;
    dfs(root, nodes);
    int n = nodes.size();
    for (int i = 0; i < n - 1; i++) 
        nodes[i]->left = nullptr, nodes[i]->right = nodes[i + 1];
    nodes[n - 1]->left = nodes[n - 1]->right = nullptr;
    return nodes[0];
}

int main() {
    return 0;
}
